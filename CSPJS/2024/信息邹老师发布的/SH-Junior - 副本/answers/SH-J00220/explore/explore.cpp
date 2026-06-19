#include <bits/stdc++.h>
using namespace std;
string mp[1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T; cin>>T;
	while(T--){
		int n,m,k; cin>>n>>m>>k;
		int x,y,d; cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			cin>>mp[i];
			mp[i]=' '+mp[i];
		}
		long long ans=1;
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='x'){
				d=(d+1)%4;
			}else{
				x=nx,y=ny;
				if(!vis[x][y]){
					ans++;
					vis[x][y]=1;
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
	}
	return 0;
}
