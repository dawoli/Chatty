// Problem URL: https://www.luogu.com.cn/problem/P17728 [SCP-J 2026] 染色 color
// Finish Time: 2026/10/20 16:55:58 AC
// Start Time: 2026/10/20 16:38:31
#include <bits/stdc++.h>
#define int ll
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 2e5 + 5;

int n, a[MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, a[i] - a[i + 1]);
	}
	if (n >= 3)
	{
		int pre = a[2];
		for (int j = 3; j <= n - 1; j++)
		{
			ans = max(ans, a[j] - pre);
			pre = min(pre, a[j]);
		}
	}
	cout << ans + a[n] - a[1] << '\n';
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：不能逐项模拟；1 与 n 同色 / 异色两类都要枚举，异色时 i,j 必须相邻。
 * - 关键结论/技巧：同色子序列的贡献望远镜求和 = 末 - 首，问题退化为选首尾。
 * - 复杂度：O(n)
 */