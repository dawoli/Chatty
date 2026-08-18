// Problem URL: https://www.luogu.com.cn/problem/T176977
// Start Time: 2026/8/17 15:10:15

#include <bits/stdc++.h>
#define int int
#define endl '\n'
#define pii pair<int, int>
using namespace std;
typedef long long ll;

int			n, l, w;
vector<pii> s;

void solve()
{
	cin >> n >> l >> w;
	s.clear();
	int le = ceil(w / 2.0);
	while (n--)
	{
		int p, r;
		cin >> p >> r;
		if (r < le)
			continue;
		s.push_back({p - r, p + r});
	}
	sort(s.begin(), s.end());
	n		  = s.size();
	int	 ans  = 0;
	bool flag = false;
	int	 st	  = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i, r = INT_MIN;
		while (j < n && s[j].first <= st)
		{
			r = max(r, s[j].second);
			j++;
		}
		if (r < st)
			break;
		ans++;
		if (r >= l)
		{
			flag = true;
			break;
		}
		st = r;
		i  = j - 1;
	}
	if (!flag)
		ans = -1;
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}