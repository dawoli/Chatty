// Problem URL: https://www.luogu.com.cn/problem/P1363
// Finish Time: 2026/10/3 17:56:21 AC
// Start Time: 2026/10/3 16:25:52

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1.5e3 + 3;

char b[MAXN][MAXN];
bool p1[MAXN * 2][MAXN * 2], p2[MAXN][MAXN];
int	 n, m, dn, dm;

bool dfs(int x, int y)
{
	if (x == -1)
	{
		if (dfs(dn - 1, y))
			return true;
		return false;
	}
	if (x == dn)
	{
		if (dfs(0, y))
			return true;
		return false;
	}
	if (y == -1)
	{
		if (dfs(x, dm - 1))
			return true;
		return false;
	}
	if (y == dm)
	{
		if (dfs(x, 0))
			return true;
		return false;
	}
	if (p1[x][y] || b[x % n][y % m] == '#')
	{
		return false;
	}
	if (p2[x % n][y % m])
	{
		return true;
	}
	p1[x][y]		 = true;
	p2[x % n][y % m] = true;
	if (dfs(x + 1, y))
		return true;
	if (dfs(x - 1, y))
		return true;
	if (dfs(x, y + 1))
		return true;
	if (dfs(x, y - 1))
		return true;
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n >> m)
	{
		dn = n * 2;
		dm = m * 2;
		int sx, sy;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> b[i][j];
				if (b[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
			}
		}
		memset(p1, 0, sizeof(p1));
		memset(p2, 0, sizeof(p2));
		if (dfs(sx, sy))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}