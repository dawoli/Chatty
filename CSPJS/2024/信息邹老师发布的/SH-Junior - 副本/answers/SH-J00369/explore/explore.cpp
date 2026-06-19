#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k,T,cnt=0;
char a[N][N];
int vis[N][N];
int x,y,d;
int x1,y1;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		cnt=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for (int i=1;i<=n;i++)
		{
			getchar();
			for (int j=1;j<=m;j++)
			{
				scanf("%c",&a[i][j]);
			}
		}
		vis[x][y]=1;
		while (k--)
		{
			if (d==0)
			{
				x1=x;
				y1=y+1;
			}
			if (d==1)
			{
				x1=x+1;
				y1=y;
			}
			if (d==2)
			{
				x1=x;
				y1=y-1;
			}
			if (d==3)
			{
				x1=x-1;
				y1=y;
			}
			if (x1>=1&&x1<=n&&y1>=1&&y1<=m)
			{
				if (a[x1][y1]=='.')
				{
					x=x1;
					y=y1;
					vis[x][y]=1;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			if (x1<1||x1>n||y1<1||y1>m)
			{
				d=(d+1)%4;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (vis[i][j]==1)
				{
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
 } 
