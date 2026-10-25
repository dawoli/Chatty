// Problem URL: https://www.luogu.com.cn/problem/P17722 [SCP-S 2026] 档案 / file
// Finish Time: 2026/10/24 21:11:59 AC
// Start Time: 2026/10/24 20:28:51

#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 6;
constexpr int MAXV = 2e6;

int n, m, a[MAXV + 10], b[MAXV + 10], w[MAXN], ans = 0, sum;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= m; i++)
	{
		int l;
		cin >> l;
		for (int j = 1; j <= l; j++)
		{
			int x;
			cin >> x;
			b[x] = i;
		}
	}
	for (int i = MAXV; i >= 1; i--)
	{
		a[i] += a[i + 1];
		if (b[i])
			w[b[i]] += a[i];
	}
	sort(w + 1, w + m + 1);
	sum = (1 + n) * n / 2;
	for (int i = 1; i <= m; i++)
		sum += w[i], ans += sum;
	cout << ans << "\n";
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：早期批的增量会被之后每次操作重复计入，系数是 m-k+1，排序升序让小的排前面；
 *   编号到 2e6 要用值域桶，答案到 1e18 要 long long。
 * - 关键结论/技巧：单批增量 w[i] = Σ(核心档案中 > x 的个数)，后缀和求；总代价 = m*sum0 + Σ w*(m-k+1)。
 * - 复杂度：O(V + L + m log m)
 */