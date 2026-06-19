#include <bits/stdc++.h>
using namespace std;
const int N=1002,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int t,n,m,k,sx,sy,sd,ans;
char g[N][N];
bool vis[N][N];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&sx,&sy,&sd);
		for (int i=1;i<=n;++i)
			scanf("%s",g[i]+1);
		memset(vis,0,sizeof(vis));
		vis[sx][sy] = 1;
		for (int i=1;i<=k;++i)
		{
			int tx=sx+dx[sd];
			int ty=sy+dy[sd];
			if (tx<=0 || tx>n || ty<=0 || ty>m || g[tx][ty]=='x') sd = (sd+1)%4;
			else
			{
				sx = tx;
				sy = ty;
				vis[sx][sy] = 1;
			}
		}
		ans = 0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				if (vis[i][j]) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
