#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, a[1005][1005], f[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				char c;
				cin >> c;
				if (c == '.')
					a[i][j] = 0;
				else
					a[i][j] = 1;
			}
		memset(f, 0, sizeof f);
		f[x][y] = 1;
		while (k--)
		{
			int x1, y1;
			if (!d)
			{
				x1 = x;
				y1 = y + 1;
			}
			;
			if (d == 1)
			{
				x1 = x + 1;
				y1 = y;
			}
			if (d == 2)
			{
				x1 = x;
				y1 = y - 1;
			}
			if (d == 3)
			{
				x1 = x - 1;
				y1 = y;
			}
			if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && !a[x1][y1])
			{
				x = x1;
				y = y1;
				f[x][y] = 1;
			}
			else
				d = (d + 1) % 4;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (f[i][j])
					cnt++;
		cout << cnt << endl;
	}
	return 0;
}
