#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010];
int ax[5]={0,1,0,-1};
int ay[5]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,ans=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		memset(vis,0,sizeof vis);
		vis[x][y]=1;
		while(k--){
			int nx=x+ax[d],ny=y+ay[d];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]=='.'){
				x=nx;
				y=ny;
			}
			else{
				d=(d+1)%4;
			}
			vis[x][y]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=vis[i][j]; 
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
