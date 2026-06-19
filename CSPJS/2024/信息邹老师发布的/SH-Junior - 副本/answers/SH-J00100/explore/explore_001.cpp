#include <bits/stdc++.h>
using namespace std;
int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool mp[1005][1005];
int vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		int n,m,k,ans=0;
		cin>>n>>m>>k;
		int sx,sy,sd;
		cin>>sx>>sy>>sd;
		vis[sx][sy]++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char tmpp;
				cin>>tmpp;
				if(tmpp=='x') mp[i][j]++; 
			}
		}
		int x=sx,y=sy,dirr=sd;//³õÊ¼»¯ dirr 
		while(k--){
			int nx = x+d[dirr][0],ny=y+d[dirr][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]==0){
				x=nx;
				y=ny;
				vis[x][y]=1;
			}else{
				dirr = (dirr+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
