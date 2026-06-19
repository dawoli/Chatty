#include <iostream>
#include <cstdio>
using namespace std;

int n, m, k, x, y, d;
bool map[1001][1001] = {}, flag[1001][1001] = {};

void move()
{
	if (d == 0)
	{
		if (y + 1 <= m && map[x][y + 1] == true)
		{
			y += 1;
			flag[x][y] = true;
		}
		else
		{
			d = (d + 1) % 4;
		}
	}
	else if (d == 1)
	{
		if (x + 1 <= m && map[x + 1][y] == true)
		{
			x += 1;
			flag[x][y] = true;
		}
		else
		{
			d = (d + 1) % 4;
		}
	}
	else if (d == 2)
	{
		if (y - 1 > 0 && map[x][y - 1] == true)
		{
			y -= 1;
			flag[x][y] = true;
		}
		else
		{
			d = (d + 1) % 4;
		}
	}
	else if (d == 3)
	{
		if (x - 1 > 0 && map[x - 1][y] == true)
		{
			x -= 1;
			flag[x][y] = true;
		}
		else
		{
			d = (d + 1) % 4;
		}
	}
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		char a;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> a;
				if (a == '.')
				{
					map[i][j] = true;
				}
			}
		}
		flag[x][y] = true;
		for (int i = 1; i <= k; ++i)
		{
			move();
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (flag[i][j] == true)
				{
					ans += 1;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
