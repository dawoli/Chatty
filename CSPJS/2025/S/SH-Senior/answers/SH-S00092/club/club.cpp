#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,a[100005][5],c0[5];
ll ans;
void dfs(int d,ll s,int x,int y,int z){
	if(d==n+1){
		if(!(x>n/2||y>n/2||z>n/2)&&ans<s) ans=s;
		return;
	}
	else{
		if(x<n/2) dfs(d+1,s+a[d][1],x+1,y,z);
		if(y<n/2) dfs(d+1,s+a[d][2],x,y+1,z);
		if(z<n/2) dfs(d+1,s+a[d][3],x,y,z+1);
	}
}
void dfs30(int d,ll s,int x,int y){
	if(d==n+1){
		if(!(x>n/2||y>n/2)&&ans<s) ans=s;
		return;
	}
	else{
		if(x<n/2) dfs30(d+1,s+a[d][1],x+1,y);
		if(y<n/2) dfs30(d+1,s+a[d][2],x,y+1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j]);
				if(a[i][j]==0) c0[j]++;
			}
		if(c0[3]==n){
			if(c0[2]==n){
				int b[100005];
				for(int i=1;i<=n;++i) b[i]=a[i][1];
				sort(b+1,b+1+n);
				for(int i=n;i>n/2;--i) ans+=b[i];
			}
			else dfs30(1,0,0,0);
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
