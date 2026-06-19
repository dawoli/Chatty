#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T;
int n,m,k;
int x,y,d;
char a[1005][1005];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
bool vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		vis[x][y]=true;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			bool flag=true;
			if(nx>n||nx<1||ny>m||ny<1) flag=false;
			else if(a[nx][ny]=='x') flag=false;
			if(flag)
			{
				x=nx,y=ny;
				vis[x][y]=true;
			}
			else d=(d+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
