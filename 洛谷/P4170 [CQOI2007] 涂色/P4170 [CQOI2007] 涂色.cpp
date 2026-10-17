// Problem URL: https://www.luogu.com.cn/problem/P4170 [CQOI2007] 涂色
// Start Time: 2026/10/17 11:54:44

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e1 + 1;

string s;
int	   n, dp[MAXN][MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int l = 1; l <= n; l++)
		for (int i = 1; i + l - 1 <= n; i++)
		{
			if (l == 1)
			{
				dp[i][i] = 1;
				continue;
			}
			const int j = i + l - 1;
			dp[i][j] = INT_MAX;
			if (s[i] == s[j])
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	cout << dp[1][n] << endl;
	return 0;
}