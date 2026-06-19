#include<bits/stdc++.h>
using namespace std;
int t;
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=0;i<=1002;i++)
			for(int j=0;j<=1002;j++) vis[i][j]=false;
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>a[i][j];
		}
		int ans=1;
		vis[x][y]=true;
		while(k--){
			int nx=x+mv[d][0];
			int ny=y+mv[d][1];
			if(nx<=0||nx>n||ny<=0||ny>m){
				d++;
				d%=4;
				continue;
			}
			if(a[nx][ny]=='x'){
				d++;
				d%=4;
				continue;
			}
			x=nx,y=ny;
			if(vis[x][y]==false){
				vis[x][y]=true;
				ans++;
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
