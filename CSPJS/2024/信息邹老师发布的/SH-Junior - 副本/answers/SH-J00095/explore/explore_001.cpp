#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char c[1010][1010];
int a[1010][1010];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans = 0;
		memset(a,0,sizeof(a));
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int rx,ry,d;
		scanf("%d%d%d",&rx,&ry,&d);
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> c[i][j];
			}
		}
		a[rx][ry] = 1;
		while(k--)
		{
			int nx = rx + dx[d],ny = ry + dy[d];
			if(nx > n || nx <= 0 || ny > m || ny <= 0 || c[nx][ny] == 'x')
			{
				d = (d + 1) % 4;
			}
			else
			{
				rx = nx;
				ry = ny;
				a[rx][ry] = 1;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++) ans += a[i][j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
