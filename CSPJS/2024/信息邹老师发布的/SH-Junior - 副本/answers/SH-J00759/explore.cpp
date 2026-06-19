#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		int n,m,k,x,y,d,a[501][501],b[501][501];
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for (int j=1;j<=n;j++)
		{
			char c[1001];
			scanf("%s",c);
			for (int l=1;l<=m;l++)
			{
				if (c[l-1]=='x') a[j][l]=1;
				else a[j][l]=0;
			}
		}
		b[x][y]=1;
		for (int j=1;j<=k;j++)
		{
			if (d==0)
			{
				if (x>=1&&y+1>=1&&x<=n&&y+1<=m&&a[x][y+1]==0) y++;
				else d=(d+1)%4;
			}
			else if (d==1)
			{
				if (x+1>=1&&y>=1&&x+1<=n&&y<=m&&a[x+1][y]==0) x++;
				else d=(d+1)%4;
			}
			else if (d==2)
			{
				if (x>=1&&y-1>=1&&x<=n&&y-1<=m&&a[x][y-1]==0) y--;
				else d=(d+1)%4;
			}
			else
			{
				if (x-1>=1&&y>=1&&x-1<=n&&y<=m&&a[x-1][y]==0) x--;
				else d=(d+1)%4;
			}
			b[x][y]=1;
		}
		int ans=0;
		for (int j=1;j<=n;j++)
		{
			for (int l=1;l<=m;l++)
			{
				if (b[j][l]==1) ans++;
			}
		}
		printf("%d\n",ans);
	}
}
