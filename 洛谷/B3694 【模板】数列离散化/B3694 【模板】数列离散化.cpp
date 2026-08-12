// Problem URL: https://www.luogu.com.cn/problem/B3694
// Finish Time: 2026/7/13 15:29:03 AC
// Finish Time: 2026/7/13 15:24:17 WA
// Finish Time: 2026/7/13 15:16:03 WA
// Start Time: 2026/7/13 14:51:16

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int		  n, a[MAXN], b[MAXN];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{

		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int len = unique(b + 1, b + n + 1) - (b + 1);

	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(b + 1, b + len + 1, a[i]) - b;
		cout << pos << " ";
	}
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
/*
 * 经验总结：
 * - 容易错的地方：lower_bound 必须用在有序区间上，
 *   在原数组上二分查找是未定义行为
 * - 关键结论/技巧：离散化三步走——拷贝→排序去重→二分查排名
 * - 复杂度：O(n log n)
 */