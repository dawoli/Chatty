// Problem URL: https://www.luogu.com.cn/problem/P8687 [蓝桥杯 2019 省 A] 糖果
// Finish Time: 2026/10/11 20:35:45 AC
// Start Time: 2026/10/11 20:06:20

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

int n, m, k;
int dp[(1 << 20) + 1], a[105] = {0};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	int num = (1 << m);
	for (int i = 1; i <= num; i++)
	{
		dp[i] = 105;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int t;
			cin >> t;
			a[i] = a[i] | (1 << (t - 1));
		}
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= num; j++)
		{
			if (dp[j] > 100)
				continue;
			int nxt = ((j - 1) | a[i]) + 1;
			dp[nxt] = (dp[nxt] < dp[j] + 1) ? dp[nxt] : dp[j] + 1;
		}
	if (dp[num] == 105)
		cout << -1 << endl;
	else
		cout << dp[num] << endl;
	return 0;
}