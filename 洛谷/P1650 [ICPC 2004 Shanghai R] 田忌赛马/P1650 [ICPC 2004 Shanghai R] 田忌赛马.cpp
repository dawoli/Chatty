// Problem URL: https://www.luogu.com.cn/problem/P1650
// Finish Time: 2026/9/2 21:03:22 WA 20pts
// Start Time: 2026/9/2 20:53:35

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 2e3 + 3;

int		   n, a[MAXN], b[MAXN], ans = 0;
deque<int> c;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	sort(a + 1, a + n + 1, greater<int>());
	sort(b + 1, b + n + 1, greater<int>());
	for (int i = 1; i <= n; i++)
		c.push_back(a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (b[i] >= c.front())
		{
			ans -= b[i] == c.back() ? 0 : 200;
			c.pop_back();
		}
		else
		{
			ans += 200;
			c.pop_front();
		}
	}
	cout << ans << endl;
	return 0;
}

// Deep in the dark, I don't need the light
// There's a ghost inside me
// It all belongs to the other side
// We live, we love, we lie