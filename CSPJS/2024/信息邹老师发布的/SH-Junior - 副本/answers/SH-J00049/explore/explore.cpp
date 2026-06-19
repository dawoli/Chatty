#include <iostream>
#include <cstdio>
using namespace std;

int dx[10] = {0, 1, 0, -1}, dy[10] = {1, 0, -1, 0}, p[10];

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	int cur = 0;
	cin >> t;
	while (t--)
	{
		int n, m, k, x, y, d, cnt = 1;
		cin >> n >> m >> k >> x >> y >> d;
		char mp[1005][1005] = {};
		bool f[1005][1005] = {false};
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> mp[i][j];
			}
		}
		f[x][y] = true;
		for (int i = 1; i <= k; ++i)
		{
			if (mp[x + dx[d]][y + dy[d]] == '.')
			{
				x += dx[d];
				y += dy[d];
				if (!f[x][y])
				{
					f[x][y] = true;
					cnt++;
				}
			}
			else
			{
				d = (d + 1) % 4;
			}
		}
		cout << cnt << endl;
	} 
	return 0;
} 
