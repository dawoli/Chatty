// Problem URL: https://www.luogu.com.cn/problem/P8548
// Finish Time: 2026/8/18 15:36:28 AC
// Finish Time: 2026/8/18 14:07:53 WA
// Start Time: 2026/8/18 11:57:07

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 5e2 + 2;
const int		  MAXn = 5e2;

int n, q, dp[MAXN][MAXN];

struct flower
{
	int c, be, fr;
} f[MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("P8548_1.in", "r", stdin);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> f[i].c >> f[i].fr >> f[i].be;
	for (int i = 0; i <= MAXn; i++)
		for (int j = 1; j <= MAXn; j++)
			dp[i][j] = -1e9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = MAXn; j >= f[i].c; j--)
		{
			for (int fr = MAXn; fr >= 0; fr--)
			{
				dp[j][fr] = max(dp[j][fr], dp[j - f[i].c][max(0, fr - f[i].fr)] + f[i].be);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int c, f;
		cin >> c >> f;
		cout << max(0, dp[c][f]) << endl;
	}
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：
 * 	 ① base 初始化不精确：必须 dp[i][0] = 0（空集满足"新鲜度 ≥ 0"），dp[i][j≥1] = -INF；
 * 	    漏置/误置会让非法状态"从 0 拔地而起"。
 * 	 ② ≥ 维转移漏 clamp：须从 dp[j-c][max(0, fr - fr_i)] 转移，否则 fr < fr_i（单株已够）
 * 	    时越界 / 漏转移，答案偏小。
 * 	 ③ 查询向后找新鲜度：状态本身就是"≥ f"，直接取 dp[c][f]，不要再 max(dp[c][f..])。
 * - 关键结论/技巧：
 * 	 二维 0/1 背包，两维性质不同：
 * 	   价格是"至多(≤)"容量维，标准逆序滚动；
 * 	   新鲜度是"至少(≥)"下限维，转移继承 max(0, fr - fr_i)——富余部分回退到空集 base(dp[*][0])。
 * 	 判断维度读题关键词："至多/不超过"→ ≤ 容量维；"大于等于/至少"→ ≥ 下限维。
 * - 复杂度：O(n·C·F)，C=F=500、n=500 ≈ 1.25e8；q ≤ 1e6 要求查询 O(1)。
 */