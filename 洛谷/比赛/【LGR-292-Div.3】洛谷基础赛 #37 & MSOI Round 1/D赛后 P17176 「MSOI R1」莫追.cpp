// Problem URL: https://www.luogu.com.cn/problem/P17176
// Finish Time: 2026/8/3 15:32:47 AC
// Finish Time: 2026/8/3 15:16:05 TLE 80pts
// Start Time: 2026/8/3 15:00:19

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long			 ll;
typedef tuple<int, int, int> tiii;
constexpr int				 MAXN = 505;
constexpr int				 MAXM = 2e4 + 4;

int			 n, m, maxe, dp[MAXN][MAXM];
vector<tiii> e;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	maxe = n / 2 - 1;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[1][0]  = 0;
	bool flag = true;
	int	 ans  = dp[0][0];
	int	 inf  = ans;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < m; i++)
			for (int j = 1; j <= maxe; j++)
			{
				int u = get<0>(e[i]), v = get<1>(e[i]), w = get<2>(e[i]);
				if (dp[u][j - 1] + w < dp[v][j])
				{
					dp[v][j] = dp[u][j - 1] + w;
					flag	 = true;
				}
			}
	}

	for (int i = 1; i <= maxe; i++)
		ans = min(ans, dp[n][i]);
	cout << (ans == inf ? -1 : ans);
	return 0;
}