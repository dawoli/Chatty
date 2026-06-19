#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, xn, y_n, ans;
char a[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		bool vis[1005][1005] = {};
		ans = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		int i;
		vis[x][y] = 1;
		ans++;
		for (i = 1; i <= k; i++)
		{
			if (d == 0)
			{
				xn = x;
				y_n = y + 1;
			}
			else if (d == 1)
			{
				xn = x + 1;
				y_n = y;
			}
			else if (d == 2)
			{
				xn = x;
				y_n = y - 1;
			}
			else if (d == 3)
			{
				xn = x - 1;
				y_n = y;
			}
			if (1 <= xn && xn <= n && 1 <= y_n && y_n <= m && a[xn][y_n] == '.')
			{
				x = xn;
				y = y_n;
				if (!vis[x][y]) ans++;
				vis[x][y] = 1;
			}
			else d = (d + 1) % 4;
		}
		cout << ans << "\n";
	}
	return 0;
}
