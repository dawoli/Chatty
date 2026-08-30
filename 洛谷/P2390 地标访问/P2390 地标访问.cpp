// Problem URL: https://www.luogu.com.cn/problem/P2390
// Finish Time: 2026/8/30 12:10:09 AC
// Start Time: 2026/8/30 11:54:03

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 5e4 + 4;

int n, t, l, r, ans;
int x[MAXN];

bool check(int a)
{
	for (int l = 1; l + a - 1 <= n; l++)
	{
		int r = l + a - 1;
		if (min(abs(x[l]), abs(x[r])) + abs(x[l] - x[r]) <= t)
			return true;
	}
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	sort(x + 1, x + n + 1);
	l = 0, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
		{
			ans = mid;
			l	= mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}