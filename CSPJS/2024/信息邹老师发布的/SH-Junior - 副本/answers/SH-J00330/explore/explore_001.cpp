#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1e3+5;
bool mp[N][N];
int vis[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		memset(mp,false,sizeof(mp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				if(c=='.') mp[i][j]=1;
			}
		}
		int ans=1;
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||ny<1||nx>n||ny>m) d=(d+1)%4;
			else if(!mp[nx][ny]) d=(d+1)%4;
			else
			{
				x=nx;
				y=ny;
				vis[x][y]++;
				if(vis[x][y]==1) ans++;
			}
			if(vis[x][y]==4) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
