// Problem URL: https://www.luogu.com.cn/problem/P1076
// Finish Time: 2026/10/4 14:30:52 AC
// Start Time: 2026/10/4 13:38:43

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MOD	= 20123;
constexpr int		   MAXN = 1e4 + 4;
constexpr int		   MAXM = 1e2 + 2;

int n, m, lo, ans = 0;

struct floor
{
	vector<int> s;
	int			x[MAXM];
} f[MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int stair;
			cin >> stair >> f[i].x[j];
			if (stair)
				f[i].s.push_back(j);
		}
	}
	cin >> lo;
	for (int i = 1; i <= n; i++)
	{
		const int &st = f[i].s.size();
		ans += f[i].x[lo], ans %= 20123;
		auto it = lower_bound(f[i].s.begin(), f[i].s.end(), lo);
		if (it == f[i].s.end())
			it = begin(f[i].s);
		const int r = (f[i].x[lo] + it - f[i].s.begin() - 1) % st;
		lo			= f[i].s[r];
	}
	cout << ans << endl;
	return 0;
}