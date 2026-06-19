#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	int dir[4][2] = {{0, 1},
				   {1, 0},
				   {0, -1},
				   {-1, 0}};
	for (int x = 0; x < t; x++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int x0, y0, d0, x1, y1, res = 1;
		cin >> x0 >> y0 >> d0;
		bool map[1005][1005];
		bool vis[1005][1005];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				char c;
				cin >> c;
				if (c == 'x')
					map[i][j] = true;
				else
					map[i][j] = false;
				vis[i][j] = false;
			}
		}
		vis[x0][y0] = true;
		for (int i = 0; i < k; i++)
		{
			x1 = x0 + dir[d0][0];
			y1 = y0 + dir[d0][1];
			if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && !map[x1][y1])
			{
				x0 = x1;
				y0 = y1;
			}
			else
			{
				d0 = (d0 + 1) % 4;
			}
			if (!vis[x0][y0])
			{
				vis[x0][y0] = true;
				res ++;
			}
		}
		cout << res << endl;
	}
	return 0;
}

