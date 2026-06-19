#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1010
int vis[N][N];
char mp[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		memset(vis,0,sizeof(vis));
		int n,m,t,x,y,d,ans=0;
		cin>>n>>m>>t>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++) cin>>(mp[i]+1);
		while(t--)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<=0||nx>=n+1||ny<=0||ny>=m+1||mp[nx][ny]=='x') d=(d+1)%4;
			else
			{
				x=nx;
				y=ny;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=vis[i][j];
		cout<<ans<<endl;
	}
	return 0;
}

