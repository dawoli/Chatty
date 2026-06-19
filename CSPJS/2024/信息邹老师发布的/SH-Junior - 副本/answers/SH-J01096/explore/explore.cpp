#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d;
char g[1005][1005];
bool vis[1005][1005];
bool check(int sx, int sy, int bo)
{
	if (bo == 0)
	{
		if ((sy + 1) > m || g[sx][sy + 1] == 'x')
		{
			return 0;
		}
	}
	else if (bo == 1)
	{
		if ((sx + 1) > n || g[sx + 1][sy] == 'x')
		{
			return 0;
		}
	}
	else if (bo == 2)
	{
		if ((sy - 1) < 1 || g[sx][sy - 1] == 'x')
		{
			return 0;
		}
	}
	else if (bo == 3) 
	{
		if ((sx - 1) < 1 || g[sx - 1][sy] == 'x')
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("explore5.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k >> x >> y >> d;
		vis[x][y] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> g[i][j];
			}
		}
		int ans = 1;
		for (int i = 1; i <= k; i++)
		{
			if (check(x, y, d))
			{
				if (d == 0)
				{
					y += 1;
				}
				else if (d == 1)
				{
					x += 1;
				}
				else if (d == 2)
				{
					y -= 1;
				}
				else if (d == 3) 
				{
					x -= 1;
				}
				if (vis[x][y] == 0) 
				{
					ans++;	
				}
				vis[x][y] = 1;
			}
			else
			{
				d += 1;
				d %= 4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
