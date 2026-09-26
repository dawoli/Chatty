// Problem URL: https://www.luogu.com.cn/problem/P3146
// Finish Time: 2026/9/2 20:06:50 AC
// Finish Time: 2026/9/1 21:30:02 WA 49pts
// Start Time: 2026/9/1 21:15:24

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 248 + 1;

int n, dp[MAXN][MAXN], ans = INT_MIN;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i][i];
		ans = max(ans, dp[i][i]);
	}
	for (int l = 2; l <= n; l++)
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j = i + l - 1;
			for (int k = i; k < j; k++)
				dp[i][j] = max({dp[i][j], dp[i][k] == dp[k + 1][j] && dp[i][k] != 0 ? dp[i][k] + 1 : INT_MIN});
			ans = max(ans, dp[i][j]);
		}
	cout << ans << endl;
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：49pts 版把 dp[i][k]、dp[k+1][j] 也放进 max 继承，dp[i][j] 的语义从
 *   "[i,j] 整段合并成一堆"退化成"[i,j] 内任取子段的最大值"，两种语义混用一个数组后，
 *   合并条件 dp[i][k]==dp[k+1][j] 失效——相等的值可能来自不相邻的散数。
 *   反例 3 1 1 3：中间 1+1→2 后成 3 2 3，两端 3 永不相邻，答案 3；错解里 dp[1][1]=3
 *   （左端孤立 3）与 dp[2][4]=3（继承自子段 [4,4] 的右端孤立 3）"相等"，被强行合成 4。
 * - 关键结论/技巧：区间 DP 的合并条件隐含要求状态语义唯一。正确做法：dp[i][j] 只表示
 *   整段合并（值域 >=1，用 0 当不可合并哨兵，转移加 !=0 防两个死状态 0==0 合成假堆）；
 *   "任取子段"的最优最后用 ans=max{dp[i][j]} 收集——最优解未必用完整段（如 2 1 1 9
 *   整段合不成一块，dp[1][n] 是死状态，但答案是单独的末尾 9）。
 * - 复杂度：O(n^3)，n<=248 约 1.5e7。
 */

// Deep in the dark, I don't need the light
// There's a ghost inside me
// It all belongs to the other side
// We live, we love, we lie