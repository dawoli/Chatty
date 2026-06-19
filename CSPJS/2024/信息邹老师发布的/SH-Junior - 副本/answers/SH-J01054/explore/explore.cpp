#include <iostream>
#include <cstdio>
using namespace std;
int T;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,k,x,y,d,ans;
bool emp[1002][1002],vis[1002][1002];
char c[1002][1002];
bool inside(int x0,int y0)
{
	return 1<=x0&&x0<=n&&1<=y0&&y0<=m;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	scanf("%d",&T);
	for (int Q=0;Q<T;Q++)
	{
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for (int i=1;i<=n;i++) cin>>c[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=m;j>=1;j--)
			{
				if (c[i][j-1]=='.') emp[i][j]=true;
				else emp[i][j]=false;
				vis[i][j]=false;
				c[i][j]=c[i][j-1];
			}
		}
		for (int i=0;i<k;i++)
		{
			vis[x][y]=true;
			if (inside(x+dx[d],y+dy[d])&&emp[x+dx[d]][y+dy[d]]) x+=dx[d],y+=dy[d];
			else d=(d+1)%4;
		}
		vis[x][y]=true;
		ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (vis[i][j])
					ans++;
		printf("%d\n",ans);
	}
    return 0;
}
