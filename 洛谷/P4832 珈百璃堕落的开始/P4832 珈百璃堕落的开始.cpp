// Problem URL: https://www.luogu.com.cn/problem/P4832
// Finish Time: 2026/8/28 10:01:21 AC
// Finish Time: 2026/8/28 09:47:51 TLE/RE 40pts
// Start Time: 2026/8/28 09:18:32

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 5e7 + 7;
const int			   MAXM = 1e6;

int n, dp[2][MAXM * 2 + 2], ans = INT_MIN, l = 0, r = 0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -0x3f3f3f3f, sizeof(dp));
	dp[0][MAXM] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string c;
		cin >> c;
		int s = 0, C = 0;
		for (auto x : c)
		{
			switch (x)
			{
			case 's':
				s++;
				break;
			case 'c':
				C++;
			}
		}
		int t = i & 1, p = t ^ 1, g = s - C;
		l = min(l, l + g), r = max(r, r + g);
		for (int j = l; j <= r; j++)
		{
			dp[t][j + MAXM] = max(dp[t][j + MAXM], dp[p][j + MAXM]);
			dp[t][j + MAXM] = max(dp[t][j + MAXM], dp[p][j - g + MAXM] + s);
		}
		ans = max(ans, dp[t][MAXM]);
	}
	cout << ans << endl;
	return 0;
}

/*
 * 经验总结：
 * - 题意：每个式子 = 若干 sin^2(pi/7)(记作 s) 与 cos^2(pi/7)(记作 c) 相加。选若干式子求和，
 *   求"最大整数答案"。由恒等式 sin^2 x + cos^2 x = 1 知，方案的和为整数 <=> 其中 s 总数 S = c 总数 C，
 *   且此时和恰为 S(=C)。故答案 = max{ S | 选中式子有 S = C }。
 * - 容易错的地方：
 *   1) 别用浮点算 sin/cos，直接统计每行 s、c 个数即可。
 *   2) 差值 s - c 可为负，数组要加全局偏移 offset；最初枚举 [0, 2m] 会 O(n*m) 超时，且 j-g 越界 RE。
 *   3) 正确做法：用 [l, r] 记录当前可达差值区间，只扫该区间，随加入式子 l=l+g、r=r+g 扩展。
 * - 关键结论/技巧：差值背包。每行作物品，重量 w = s - c（可为负），价值 = s；
 *   dp[j] = 已选式子差值总和为 j 时 s 个数和的最大值，答案 = dp[0]（差值 0 ⇒ S=C ⇒ 整数 = S）。
 *   转移 dp[t][j] = max(dp[p][j](不选), dp[p][j-w] + s(选))，两行按 i&1 滚动。
 * - 复杂度：差值最多扩到 m，总工作量 O(sum_i 当前差值区间宽) <= O(n*m)，由 n*m <= 5e7 卡稳；空间 O(2m) ~ 16 MB。
 */