// Problem URL: https://www.luogu.com.cn/contest/352393
// Finish Time: 2026/8/30 13:49:44 AC
// Start Time: 2026/8/30 13:29:05

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e5 + 5;

int t, n, a[MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << max(a[1], a[n]) << endl;
	}
	return 0;
}