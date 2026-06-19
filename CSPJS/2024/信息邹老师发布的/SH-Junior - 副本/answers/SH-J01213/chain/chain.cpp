#include <bits/stdc++.h>
using namespace std;

int n, k, q, l[1005], dp[105][105][105];

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof dp);
		vector<int> s[1005], g[105][205];
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++)
		{
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++)
			{
				int x;
				cin >> x;
				s[i].push_back(x);
			}
			for (int j = 0; j < s[i].size(); j++)
			{
				for (int l = 2; l <= k && j + l - 1 < s[i].size(); l++)
				{
					int u = s[i][j];
					int v = s[i][j + l - 1];
					g[i][v].push_back(u);
				}
			}
		}
		dp[0][1][1] = 1;
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= 10; k++)
					for (int l = 0; l < g[j][k].size(); l++)
					{
						int x = g[j][k][l];
						for (int y = 1; y <= n; y++)
						{
							if (y == j) continue;
							dp[i][j][k] |= dp[i - 1][y][x];
						}
					}
		for (int i = 1; i <= q; i++)
		{
			int x, y;
			cin >> x >> y;
			int ans = 0;
			for (int j = 1; j <= n; j++) ans |= dp[x][j][y];
			cout << ans << "\n";
		}
	}
	return 0;
}
