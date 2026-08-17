// Problem URL: https://www.luogu.com.cn/problem/P1799
// Finish Time: 2026/8/13 14:00:40 AC
// Finish Time: 2026/8/13 11:29:02 WA 10pts
// Finish Time: 2026/8/13 11:16:44 WA 20pts
// Finish Time: 2026/8/13 11:14:43 WA 20pts
// Finish Time: 2026/8/13 11:10:03 WA 20pts
// Finish Time: 2026/8/13 11:04:18 WA 20pts
// Start Time: 2026/8/13 10:44:32

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e3 + 3;

int n, a[MAXN], dp[MAXN][MAXN], ans = INT_MIN;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i][0] = dp[i - 1][0];
		if (a[i] == i)
			dp[i][0]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i][j] = max({dp[i][j], dp[i - 1][j - 1], dp[i - 1][j] + (a[i] == i - j)});
			if (i == n)
				ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 0; j < i; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << b[i][j] << " ";
	// 	cout << endl;
	// }
	return 0;
}