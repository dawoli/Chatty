#include<bits/stdc++.h>
using namespace std;
ifstream fin("explore.in");
ofstream fout("explore.out");
const int N=1010;
char a[N][N];
int main()
{
	int T;
	fin>>T;
	while(T--)
	{
		int n,m,k,x,y,d;
		fin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				fin>>a[i][j];
			}
		}
		int cntt=1;
		bool vis[N][N];
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		while(k--)
		{
			int nx=0,ny=0;
			if(d==0)
			{
				nx=x;
				ny=y+1;
			}
			else if(d==1)
			{
				nx=x+1;
				ny=y;
			}
			else if(d==2)
			{
				nx=x;
				ny=y-1;
			}
			else
			{
				nx=x-1;
				ny=y;
			}
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]=='.')
			{
				if(vis[nx][ny]==0)
				{
					cntt++;
				}
				x=nx;
				y=ny;
				vis[nx][ny]=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		fout<<cntt<<endl;
	}
	return 0;
}
