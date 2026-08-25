// Problem URL: https://www.luogu.com.cn/problem/P8806
// Finish Time: 2026/8/19 15:27:17 AC
// Start Time: 2026/8/19 15:10:59

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN	  = 1e3 + 3;
const int		  MAX_SUM = 1e3 * 2e4 + 2;

struct brick
{
	int w, v;
} a[MAXN];

bool operator<(const brick &_a, const brick &_b)
{
	return _a.w + _a.v < _b.w + _b.v;
}

int n, dp[MAX_SUM], ans = INT_MIN;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].w >> a[i].v;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = a[i].w + a[i].v; j >= a[i].w; j--)
		{
			dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
			ans	  = max(dp[j], ans);
		}
	cout << ans << endl;
	return 0;
}