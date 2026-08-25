// Problem URL: https://www.luogu.com.cn/problem/P8810
// Finish Time: 2026/8/23 18:05:11 AC
// Start Time: 2026/8/20 11:59:07

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e3 + 3;
const int		  MAXV = 1e1 + 1;
const int		  MOD  = 1e9 + 7;

int n, b[MAXN], dp[MAXN][MAXV][MAXV], ans = 0, mx = INT_MIN;

void DP(int x, int y)
{
	memset(dp, 0, sizeof(dp));
	dp[2][x][y] = 1;
	for (int i = 3; i <= n; i++)
		for (int j = 0; j <= b[i - 1]; j++)
			for (int k = 0; k <= b[i - 1]; k++)
				for (int m = 0; m <= b[i - 1]; m++)
				{
					if (max({j, k, m}) != b[i - 1])
						continue;
					dp[i][j][k] += dp[i - 1][m][j];
					dp[i][j][k] %= MOD;
				}
	for (int i = 0; i <= mx; i++)
		for (int j = 0; j <= mx; j++)
		{
			if (max({i, j, x}) != b[n] || max({j, x, y}) != b[1])
				continue;
			ans += dp[n][i][j];
			ans %= MOD;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		mx = max(mx, b[i]);
	}
	for (int i = 0; i <= mx; i++)
		for (int j = 0; j <= mx; j++)
			DP(i, j);
	cout << ans << endl;
	return 0;
}