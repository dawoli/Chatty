// Problem URL: https://www.luogu.com.cn/problem/P15848 [NOISG 2026 Finals] 饿猫 / Famished Cats
// Finish Time: 2026/10/21 21:31:57 WA
// Start Time: 2026/10/21 17:04:53

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e5 + 5;

int					n, x, d[MAXN], f[MAXN], ans = 0, s = 0;
priority_queue<pii> q;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	for (int i = 1; i <= n / 2 + 1; i++)
	{
		int add = 0;
		while (x < d[i] && !q.empty())
		{
			x += q.top().first;
			swap(f[q.top().second], f[n - q.top().second + 1]);
			q.pop();
			s++;
			add++;
		}
		if (f[i] < f[n - i + 1])
			q.push({f[n - i + 1] - f[i], i});
		if (x < d[i])
		{
			s -= add;
			break;
		}
		x -= d[i];
		ans++;
		x += f[i];
	}
	for (int i = n / 2 + 2; i <= n; i++)
	{
		if (x < d[i])
			break;
		x -= d[i];
		ans++;
		x += f[i];
	}
	cout << ans << " " << s << endl;
	return 0;
}