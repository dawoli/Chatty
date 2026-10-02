// Problem URL: https://www.luogu.com.cn/problem/P12225
// Finish Time: 2026/10/2 12:32:58 TLE 65pts
// Finish Time: 2026/10/2 12:30:33 TLE/RE 65pts
// Start Time: 2026/10/2 12:10:38

#include <bits/stdc++.h>
#define int int
#define endl '\n'
#define MAX 0
#define MIN 1
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 1e5 + 5;

int		   n, k, a, m[MAXN][2];
ll		   ans1;
double	   ans2;
deque<pii> mx, mn;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (!mx.empty() && mx.front().second < i - k + 1)
			mx.pop_front();
		if (!mn.empty() && mn.front().second < i - k + 1)
			mn.pop_front();
		while (!mx.empty() && mx.back().first <= a)
			mx.pop_back();
		mx.push_back({a, i});
		while (!mn.empty() && mn.back().first >= a)
			mn.pop_back();
		mn.push_back({a, i});
		if (i >= k)
			m[i][MAX] = mx.front().first, m[i][MIN] = mn.front().first;
	}
	for (int i = k; i <= n; i++)
		for (int j = k; j <= n; j++)
			ans1 += m[i][MAX] - m[j][MIN];
	ans2 = (double)ans1 / (n - k + 1) / (n - k + 1);
	cout << fixed << setprecision(2) << ans2 << endl;
	return 0;
}