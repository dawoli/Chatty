// Problem URL: https://www.luogu.com.cn/problem/P12349
// Finish Time: 2026/8/25 12:21:16 AC
// Start Time: 2026/8/25 11:54:39

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e3 + 3;

int	 n, m, dp[MAXN][2][2];
char c[MAXN][MAXN];

auto val(int i, int x, int y, int z)
{
	int res = 0;
	for (int j = 0; j < m; j++)
	{
		int cnt = 0;
		if (j > 0 && c[i][j] == c[i][j - 1])
			cnt++;
		if (j < m - 1 && c[i][j] == c[i][j + 1])
			cnt++;
		if (i > 0)
			cnt += (c[i][j] == c[i - 1][j]) ^ x ^ y;
		if (i < n - 1)
			cnt += (c[i][j] == c[i + 1][j]) ^ y ^ z;
		res += cnt * cnt;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
	{
		dp[i][0][0] = max(dp[i - 1][0][0] + val(i - 1, 0, 0, 0),
						  dp[i - 1][0][1] + val(i - 1, 1, 0, 0));
		dp[i][0][1] = max(dp[i - 1][1][0] + val(i - 1, 0, 1, 0),
						  dp[i - 1][1][1] + val(i - 1, 1, 1, 0));
		dp[i][1][0] = max(dp[i - 1][0][0] + val(i - 1, 0, 0, 1),
						  dp[i - 1][0][1] + val(i - 1, 1, 0, 1));
		dp[i][1][1] = max(dp[i - 1][1][0] + val(i - 1, 0, 1, 1),
						  dp[i - 1][1][1] + val(i - 1, 1, 1, 1));
	}
	cout << max({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]});
	return 0;
}