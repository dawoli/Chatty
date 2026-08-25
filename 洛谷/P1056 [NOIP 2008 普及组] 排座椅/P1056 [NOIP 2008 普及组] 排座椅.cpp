// Problem URL: https://www.luogu.com.cn/problem/P1056
// Finish Time: 2026/8/25 11:44:34 AC
// Finish Time: 2026/8/24 21:00:51 WA 50pts
// Start Time: 2026/8/24 20:39:05

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 1e3 + 3;
const int			   MAXD = 2e3 + 3;

int			n, m, k, l, d;
pii			ln[MAXN], co[MAXN];
vector<int> ln1, co1;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k >> l >> d;
	for (int i = 1; i < n; i++)
		ln[i].second = i;
	for (int i = 1; i < m; i++)
		co[i].second = i;
	for (int i = 1; i <= d; i++)
	{
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		if (x == p)
			co[min(y, q)].first++;
		else
			ln[min(x, p)].first++;
	}
	sort(ln + 1, ln + n + 1, greater<pii>());
	sort(co + 1, co + n + 1, greater<pii>());
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt >= k)
			break;
		ln1.push_back(ln[i].second);
		cnt++;
	}
	cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (cnt >= l)
			break;
		co1.push_back(co[i].second);
		cnt++;
	}
	sort(ln1.begin(), ln1.end());
	sort(co1.begin(), co1.end());
	for (auto i : ln1)
		cout << i << " ";
	cout << endl;
	for (auto i : co1)
		cout << i << " ";
	return 0;
}