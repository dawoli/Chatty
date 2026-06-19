#include <bits/stdc++.h>
using namespace std;

int t;

void Work()
{
	int n, m, k;
	int d, x, y;
	int tx, ty;
	long long ans = 0;
	bool mp[1005][1005] = {0};
	bool vis[1005][1005] = {0};
	int zx[10] = {0, 1, 0, -1};
	int zy[10] = {1, 0, -1, 0};
	cin >> n >> m >> k;
	cin >> x >> y >> d;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'x') mp[i][j + 1] = false;
			else if (s[j] == '.') mp[i][j + 1] = true;
		}
	}
	vis[x][y] = true;
	for (int i = 1; i <= k; i++)
	{
		tx = x + zx[d];
		ty = y + zy[d];
		if (1 <= tx && tx <= n && 1 <= ty && ty <= m && mp[tx][ty])
		{
			vis[tx][ty] = true;
			x = tx;
			y = ty;
		}
		else
		{
			d = (d + 1) % 4;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans += vis[i][j];
		}
	}
	cout << ans << endl;
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) Work();
	return 0;
}
