// Problem URL: https://www.luogu.com.cn/problem/P2858
// Finish Time: 2026/8/19 15:48:26 AC
// Start Time: 2026/8/19 15:31:18

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 2e3 + 3;

int n, v[MAXN], dp[MAXN][MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		dp[i][i] = v[i] * n;
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j	 = i + l - 1;
			dp[i][j] = max(dp[i + 1][j] + v[i] * (n - l + 1), dp[i][j - 1] + v[j] * (n - l + 1));
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}