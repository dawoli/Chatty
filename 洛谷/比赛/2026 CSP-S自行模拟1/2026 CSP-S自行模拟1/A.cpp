// Problem URL: https://www.luogu.com.cn/contest/365930
// Finish Time: 2026/10/18 11:13:34 AC
// Start Time: 2026/10/18 10:56:48

#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 5;

int n, a[MAXN], ans = 0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
		if (a[i] > a[i - 1])
			ans += a[i] - a[i - 1];
	cout << ans + a[1] << '\n';
	return 0;
}

/*
 * 经验总结：
 * - 关键结论/技巧：总和 = a[1] + 所有上升段的增量 Σmax(0, a[i]-a[i-1])。
 * - 复杂度：O(n)
 */