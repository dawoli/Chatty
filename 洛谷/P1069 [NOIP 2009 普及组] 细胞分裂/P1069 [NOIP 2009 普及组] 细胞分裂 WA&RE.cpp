// Problem URL: https://www.luogu.com.cn/problem/P1069
// Finish Time: 2026/10/2 21:54:36 WA/RE 40pts
// Finish Time: 2026/10/2 21:51:24 WA/RE 30pts
// Start Time: 2026/10/2 21:21:07

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e4 + 4;

int				   n, m1, m2, s, ans = INT_MAX;
unordered_set<int> fm;

unordered_set<int> factorize(int x)
{
	unordered_set<int> factors;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			factors.insert(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x > 1)
		factors.insert(x);
	return factors;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m1 >> m2;
	fm = factorize(m1);
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int x = 0, pw = 1;
		if (s % 2 != 0 && m1 % 2 == 0)
			continue;
		auto fs = factorize(s);
		for (auto f : fm)
		{
			if (fs.find(f) == fs.end())
			{
				x = -1;
				break;
			}
		}
		if (x == -1)
			continue;
		while (pw % m1 != 0)
		{
			pw *= s;
			x++;
		}
		int q = pw / m1, y = 1;
		for (;; y++)
		{
			if (y >= m2 / q)
				break;
			q *= q;
		}
		ans = min(ans, x + y - 1);
		// cout << "s: " << s << ", x: " << x << ", y: " << y << ", ans: " << ans << endl;
	}
	if (ans == INT_MAX)
		ans = -1;
	cout << ans << endl;
	return 0;
}