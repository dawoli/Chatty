#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, tx, ty, ans;
bool v[1005][1005];
char c[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(v, 0, sizeof(v));
		ans = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> c[i][j];
		v[x][y] = true;
		ans++;
		while (k--)
		{
			tx = x + dx[d], ty = y + dy[d];
			if (tx < 1 || tx > n || ty < 1 || ty > m || c[tx][ty] != '.')
			{
				d = (d + 1) % 4;
			}
			else
			{
				x = tx, y = ty;
				if (!v[x][y])
				{
					ans++;
					v[x][y] = true;
				}
			}
		}
		cout << ans << endl;
	}
}
