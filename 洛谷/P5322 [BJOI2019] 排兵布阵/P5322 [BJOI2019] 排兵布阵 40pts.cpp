// Problem URL: https://www.luogu.com.cn/problem/P5322
// Finish Time: 2026/9/6 11:02:18 WA 40pts
// Start Time: 2026/9/6 10:46:14

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e2 + 2;
const int		  MAXM = 2e4 + 4;

set<int> c[MAXN];
int		 s, n, m, dp[MAXM], ans = INT_MIN;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> n >> m;
	for (int i = 1; i <= s; i++)
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			c[j].insert(x);
		}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 0; j--)
		{
			int cnt = 1;
			for (auto b : c[i])
			{
				const int p = 2 * b + 1;
				if (p > j)
					break;
				dp[j] = max(dp[j], dp[j - p] + cnt * i);
				cnt++;
			}
			if (cnt == 1)
				break;
		}
	cout << dp[m] << endl;
	return 0;
}