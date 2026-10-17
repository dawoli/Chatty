// Problem URL: https://www.luogu.com.cn/problem/P7912 [CSP-J 2021] 小熊的果篮
// Finish Time: 2026/10/6 16:44:35 TLE 50pts
// Start Time: 2026/10/6 16:04:37

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

int		 n, s;
set<int> p[2];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		p[x].insert(i);
	}
	if (p[0].find(1) != p[0].end())
		s = 0;
	else
		s = 1;
	while (!p[0].empty() && !p[1].empty())
	{
		int x = min(*p[s].begin(), *p[s ^ 1].begin());
		if (x == *p[s ^ 1].begin())
			s ^= 1;
		while (true)
		{
			auto it = lower_bound(p[s].begin(), p[s].end(), x);
			if (it == p[s].end())
				break;
			cout << *it << " ";
			x = *it;
			p[s].erase(it);
			s ^= 1;
		}
		cout << endl;
	}
	if (p[s].empty())
		s ^= 1;
	for (const auto &i : p[s])
		cout << i << endl;
	return 0;
}