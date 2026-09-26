// Problem URL: https://www.luogu.com.cn/contest/352393
// Finish Time: 2026/8/30 14:22:08 WA/TLE 23pts
// Start Time: 2026/8/30 13:29:05

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MOD  = 998244353;
const int		  MAXN = 3e5 + 5;

string			   a;
int				   n, q;
vector<int>		   t[MAXN];
unordered_set<int> l;

int cnt()
{
	if (a[0] == 'U')
		return 0;
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i - 1] == 'D')
		{
			if (l.find(i) != l.end())
				return 0;
		}
		else if (a[i - 1] == '?')
		{
			if (l.find(i) == l.end())
				ans *= 2;
		}
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	cin >> a;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for (int i = 2; i <= n; i++)
		if (t[i].size() == 1)
			l.insert(i);
	cout << cnt() << endl;
	for (int i = 1; i <= q; i++)
	{
		int x;
		cin >> x >> a[x - 1];
		cout << cnt() << endl;
	}
	return 0;
}