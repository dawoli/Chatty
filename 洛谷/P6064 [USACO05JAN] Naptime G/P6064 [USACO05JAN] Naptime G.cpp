// Problem URL: https://www.luogu.com.cn/problem/P6064
// Finish Time: 2026/8/17 复盘：WA 根因是倍长数组重复选同一小时（思路缺陷），改用断环分类两遍 DP 可 AC
// Finish Time: 2026/8/14 12:07:45 WA/RE 63pts
// Finish Time: 2026/8/14 11:37:30 WA/RE 14pts
// Start Time: 2026/8/14 11:20:36

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 3080 + 12;

int n, b, u[MAXN * 2], dp[2][MAXN][2];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("P6064_7.in", "r", stdin);

	cin >> n >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> u[i];
		u[n + i] = u[i];
	}
	for (int i = 2; i <= n * 2; i++)
	{
		for (int j = 2; j <= min(i, b); j++)
		{
			int t = i & 1, p = t ^ 1;
			dp[t][j][0] = max(dp[p][j][0], dp[p][j][1]);
			dp[t][j][1] = max(dp[p][j - 1][1] + u[i], dp[p][j - 1][0]);
			// cout << dp[t][j][0] << "-" << dp[t][j][1] << " ";
		}
		// cout << endl;
	}
	cout << max(dp[(n * 2) & 1][b][0], dp[(n * 2) & 1][b][1]) << endl;
	return 0;
}
/*
 * 经验总结：
 * - 容易错的地方：倍长数组把每个小时复制成两份（位置 i 与 i+N），本题 DP 要任选 B 个位置
 *   且可多段小睡，DP 只认位置序号、不认物理小时，会同时选中同一小时的两份，把最优小睡段
 *   复制一份白拿收益 → 答案偏大（P6064_7 实测多算 3,337,926）。初始化也有 bug：dp[1] 层
 *   未正确设置、j 循环从 2 起跳过了 0/1 状态，但即使全部修好，倍长思路本身依然错。
 * - 关键结论/技巧：环上 DP 用倍长数组的前提是"解天然落在长度 ≤ N 的连续窗口内"（如环形
 *   最大子段和）；对"任意选点 + 多段"的 DP，防重复 ⟺ 限制选中跨度 ≤ N−1（鸽笼），但强制
 *   跨度需枚举窗口起点，O(N²B) 不可行。正确做法：不倍长，在 1 号处断环分两遍 DP
 *   （1 号不睡 / 1 号睡，第二遍末尾若 N 号也睡则补 +u[1] 处理 N→1 延续）。
 * - 复杂度：O(N·B)，滚动数组 O(B)。
 */