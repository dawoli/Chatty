// Problem URL: https://www.luogu.com.cn/problem/P2058
// Finish Time: 2026/10/3 13:19:36 AC
// Start Time: 2026/10/3 13:04:07

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;
constexpr int		   DAY	= 86400;

int		   n, c[MAXN], cnt = 0;
queue<pii> q;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, k;
		cin >> t >> k;
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			q.push({x, t});
			if (c[x] == 0)
				cnt++;
			c[x]++;
		}
		while (q.front().second <= t - DAY)
		{
			auto &x = q.front();
			if (c[x.first] != 0)
				c[x.first]--;
			if (c[x.first] == 0)
				cnt--;
			q.pop();
		}
		cout << cnt << endl;
	}
	return 0;
}