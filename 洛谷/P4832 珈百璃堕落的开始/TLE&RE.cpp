// Problem URL: https://www.luogu.com.cn/problem/P4832
// Start Time: 2026/8/28 09:18:32

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 5e7 + 7;
const int			   MAXM = 1e6;

int n, dp[2][MAXM * 2 + 2], ans = INT_MIN;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -0x3f3f3f3f, sizeof(dp));
	dp[0][MAXM] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string c;
		cin >> c;
		int s = 0, C = 0;
		for (auto x : c)
		{
			switch (x)
			{
			case 's':
				s++;
				break;
			case 'c':
				C++;
			}
		}
		int t = i & 1, p = t ^ 1, g = s - C;
		for (int j = 0; j <= 2 * MAXM; j++)
			dp[t][j] = max(dp[p][j], dp[p][j - g] + s);
		ans = max(ans, dp[t][MAXM]);
	}
	cout << ans << endl;
	return 0;
}