#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, x, y, d, ans = 1;
char s;
bool ditu[1010][1010], shifouquguo[1010][1010];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> s;
				if (s == '.')
				{
					ditu[i][j] = 1;
				}
				else
				{
					ditu[i][j] == 0;
				}
			}
		}
		for (int i = 1; i <= k; ++i)
		{
			if (d == 0)
			{
				if (ditu[x][y + 1])
				{
					y++;
					shifouquguo[x][y] = 1;
				}
				else
				{
					d = 1;
					shifouquguo[x][y] = 1;
				}
			}
			else if (d == 1)
			{
				if (ditu[x + 1][y])
				{
					x++;
					shifouquguo[x][y] = 1;
				}
				else
				{
					d = 2;
					shifouquguo[x][y] = 1;
				}
			}
			else if (d == 2)
			{
				if (ditu[x][y - 1])
				{
					y--;
					shifouquguo[x][y]++;
				}
				else
				{
					d = 3;
					shifouquguo[x][y] = 1;
				}
			}
			else
			{
				if (ditu[x - 1][y])
				{
					x--;
					shifouquguo[x][y]++;
				}
				else
				{
					d = 0;
					shifouquguo[x][y] = 1;
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (i == x && j == y)
				{
					continue;
				}
				else
				{
					if (shifouquguo[i][j])
					{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
		ans = 1;
	}
	return 0;
}
