// Problem URL: https://www.luogu.com.cn/problem/P2919
// Finish Time: 2026/9/26 21:14:52 WA 86pts
// Start Time: 2026/9/26 20:41:38

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 7e2 + 2;

int	 n, m, h[MAXN][MAXN], ans = 0;
bool vis[MAXN][MAXN];
pii	 dir[8] = {{0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}};

void dfs(int x, int y)
{
	if (vis[x][y])
		return;
	vis[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		if (h[x + dir[i].first][y + dir[i].second] == h[x][y])
			dfs(x + dir[i].first, y + dir[i].second);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> h[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 8; k++)
				if (h[i + dir[k].first][j + dir[k].second] > h[i][j])
				{
					dfs(i, j);
					break;
				}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j])
			{
				ans++;
				dfs(i, j);
			}
	cout << ans << endl;
	return 0;
}