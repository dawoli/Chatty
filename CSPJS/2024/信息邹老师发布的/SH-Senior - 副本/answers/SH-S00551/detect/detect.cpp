#include<bits/stdc++.h>
using namespace std;
int a[100010][3],b[100010];
bool c[100010];
int dfs(int ans,int x,int m,int all){
	if(ans==0) return 1;
	memset(c,1,sizeof(c));
	int sum=0;
	for(int i=1;i<=x;i++){
		if(!a[i][2]) continue;
		for(int j=1;j<=m;j++){
			if(b[j]>a[i][1]) break;
			if(a[i][0]<=b[j]&&c[i]){
				c[i]=0; 
				break;
			}
		}
		if(c[i]) return all;
	}
		for(int j=1;j<=m;j++){
			if(!b[j]) continue;
			int y=b[j];
			b[j]=0;
			ans=min(ans,dfs(ans-1,x,m,all));
			b[j]=y;
		}
		return min(ans,all);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T>0){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		int n,m,l,v,x=0,minr=1e3+1,maxr=-1e3-1;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			int d,vni,r; cin>>d>>vni>>r;
			minr=min(r,minr),maxr=max(r,maxr);
			int left=v*v-vni*vni;
			r*=2;
			if(left==0&&r>0)a[++x][0]=d+1,a[x][1]=l;
			else if(left<0&&r>0) a[++x][0]=d,a[x][1]=l;
			else if(r==0&&vni>v)a[++x][0]=d,a[x][1]=l;
			else if(left<0&&r<0){
				left=-left,r=-r;
				int yushu=left%r;
				if(yushu) a[++x][0]=d,a[x][1]=d+left/r;
				else a[++x][0]=d,a[x][1]=d+left/r-1;
			} 
			else if(left>0&&r>0) a[++x][0]=d+left/r+1,a[x][1]=l;
		}
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(b+1,b+m+1);
		if(minr>=0){
			int ans=0;
			for(int i=1;i<=x;i++){
				if(a[i][0]<=b[m]) ans++;
			}
			if(ans) cout<<ans<<" "<<m-1<<endl;
			else cout<<0<<" "<<m<<endl; 
		}
		else{
			int sum=0,all=0;
			for(int i=1;i<=x;i++){
				for(int j=1;j<=m;j++){
					if(a[i][0]<=b[j]&&b[j]<=a[i][1]){
						a[i][2]++;
						all++;
					}
				}
				if(a[i][2]) sum++;
			}
			cout<<sum<<" ";
			if(sum==0) cout<<m<<endl;
			else if(all%sum==0) cout<<m-all/sum<<endl;
			else cout<<m-all/sum+1<<endl;
		}
		T--;
	}
	return 0;
}

