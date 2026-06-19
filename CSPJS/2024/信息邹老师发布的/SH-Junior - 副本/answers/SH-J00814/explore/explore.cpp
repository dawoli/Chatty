#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,k,x,y,d,nx,ny,ans;
char p;
int a[1005][1005],vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		memset(vis,0,sizeof(vis));
		ans = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		vis[x][y] = 1;
		for (int j = 1;j <= n;j++)
		{
			for (int q = 1;q <= m;q++)
			{
				cin >> p;
				if (p == '.') a[j][q] = 1;
				else a[j][q] = 0;
			}
		}
		for (int j = 1;j <= k;j++)
		{
			nx = x,ny = y;
			if (d == 0) ny++;
			if (d == 1) nx++;
			if (d == 2) ny--;
			if (d == 3) nx--;
			if (1<=nx && nx<=n && 1<=ny && ny<=m && a[nx][ny]==1)
			{
				x = nx;
				y = ny;
				vis[x][y] = 1;
			}
			else
			{
				d = (d+1)%4;
			}
		}
		for (int j = 1;j <= n;j++)
		{
			for (int q = 1;q <= m;q++)
			{
				if (vis[j][q]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
