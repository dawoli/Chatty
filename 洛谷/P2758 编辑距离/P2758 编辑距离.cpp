// Problem URL: https://www.luogu.com.cn/problem/P2758
// Finish Time: 2026/8/19 14:50:22 AC
// Start Time: 2026/8/19 14:39:18

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 2e3 + 3;

int	   n, m, dp[MAXN][MAXN];
string a, b;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	n = a.size(), m = b.size();
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < MAXN; i++)
	{
		dp[0][i] = i;
		dp[i][0] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			else
				dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}