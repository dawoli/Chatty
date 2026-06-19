#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
bool vis[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int scr=1;
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];vis[i][j]=0;}}
		vis[x][y]=1;
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1 and nx<=n and a[nx][ny]=='.' and ny>=1 and ny<=m){
				x=nx;
				y=ny;
				if(vis[x][y]==0) scr++;
				vis[x][y]=1;
			}else d = (d + 1) % 4;
		}
//		for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//		cout<<vis[i][j];
//		cout<<"\n";
//		}
		cout<<scr<<"\n";
	}
	return 0;
}
