#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ct;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		ct=0;
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')d=(d+1)%4;
			else{
				vis[nx][ny]=1;
				x=nx;
				y=ny;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ct++;
			}
		}
		cout<<ct<<"\n";
	}
	return 0;
}
