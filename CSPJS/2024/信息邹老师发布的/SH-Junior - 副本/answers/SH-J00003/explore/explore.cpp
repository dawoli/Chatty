#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1010][1010];
bool vis[1010][1010];
void work(){
	cin>>n>>m>>k>>x>>y>>d;ans=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
	memset(vis,0,sizeof(vis));vis[x][y]=1;
	while(k--){
		int nx=x+dx[d],ny=y+dy[d];
		if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')d=(d+1)%4;
		else{
			if(!vis[nx][ny])ans++,vis[nx][ny]=1;
			x=nx,y=ny;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	while(t--)work();
	return 0;
}
