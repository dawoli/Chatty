#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][5];
int ans=0;
void dfs(int id,int x,int y,int z,int cnt){
	if(x>n/2||y>n/2||z>n/2){
		return;
	}
	if(id>n){
		ans=max(ans,cnt);
		return;
	}
	dfs(id+1,x+1,y,z,cnt+a[id][1]);
	dfs(id+1,x,y+1,z,cnt+a[id][2]);
	dfs(id+1,x,y,z+1,cnt+a[id][3]);
}
void solve_double(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i][1];
	}
	int tmp[100005];
	for(int i=1;i<=n;i++){
		tmp[i]=a[i][1]-a[i][2];
	}
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n/2;i++){
		cnt-=tmp[i];
	}
	cout<<cnt<<endl;
	return;
}
void solve(){
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
	ans=0;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=1,flag2=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j!=1&&a[i][j]){
					flag=0;
				}
				if(j==3&&a[i][j]){
					flag2=0;
				}
			}
		}
		if(n==2){
			int idx=1;
			if(a[1][2]>a[1][idx]){
				idx=2;
			}
			if(a[1][3]>a[1][idx]){
				idx=3;
			}
			int idx2=1;
			if(a[2][2]>a[2][idx2]){
				idx2=2;
			}
			if(a[2][3]>a[2][idx2]){
				idx2=3;
			}
			if(idx==idx2){
				int xx=-1,yy=-1;
				for(int i=1;i<=3;i++){
					if(i!=idx){
						if(xx==-1||a[1][i]>a[1][xx]){
							xx=i;
						}
					}
					if(i!=idx2){
						if(yy==-1||a[2][i]>a[2][yy]){
							yy=i;
						}
					}
				}
				cout<<max(a[1][idx]+a[2][yy],a[1][xx]+a[2][idx2])<<endl;
			}
			else{
				cout<<a[1][idx]+a[2][idx2]<<endl;
			}
			continue;
		}
		if(flag){
			int tmp[100005]={0};
			for(int i=1;i<=n;i++){
				tmp[i]=a[i][1];
			}
			sort(tmp+1,tmp+n+1);
			int ans=0;
			for(int i=n;i>n/2;i--){
				ans+=tmp[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(flag2){
			solve_double();
			continue;
		}
		if(n<=15){
			solve();
		}
		else{
			int x,y,z;
			x=y=z=0;
			for(int i=1;i<=n;i++){
				int t=1;
				if(x>=n/2){
					t=2;
				}
				if(a[i][t]<a[i][2]&&y<n/2){
					t=2;
				}
				if(a[i][t]<a[i][3]&&z<n/2){
					t=3;
				}
				if(t==1){
					x++;
				}
				if(t==2){
					y++;
				}
				if(t==3){
					z++;
				}
				ans+=a[i][t];
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
