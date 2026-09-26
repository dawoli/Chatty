// Problem URL: https://www.luogu.com.cn/problem/P5322
// Finish Time: 2026/9/7 16:28:08 AC
// Finish Time: 2026/9/6 11:02:18 WA 40pts
// Start Time: 2026/9/6 10:46:14

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e2 + 2;
const int		  MAXM = 2e4 + 4;

map<int, int> c[MAXN];
int			  s, n, m, dp[MAXM], ans = INT_MIN;

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
			c[j][x]++;
		}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 0; j--)
		{
			int cnt = 0;
			for (auto cas : c[i])
			{
				const int b = cas.first, t = cas.second;
				const int p = 2 * b + 1;
				cnt += t;
				if (p > j)
					break;
				dp[j] = max(dp[j], dp[j - p] + cnt * i);
			}
		}
	cout << dp[m] << endl;
	return 0;
}

/*
在一列里有多个相同的城堡，此时要用map存储每个城堡的数量，
随后在统计时加上这些数量，否则会漏算
注意在转移时攻下多个城堡额代价和攻下一个城堡的代价是相同的
*/