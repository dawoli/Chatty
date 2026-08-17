#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 3830 + 12;
const int		  INF  = 0x3f3f3f3f;

int n, b, u[MAXN];
int dp[2][MAXN][2];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("P6064_7.in", "r", stdin);

	cin >> n >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> u[i];
	}

	// ==========第一轮DP：强制第1段不睡觉==========
	memset(dp, -0x3f, sizeof(dp));
	dp[1 & 1][0][0] = 0; // 1号不睡，选0个，收益0

	for (int i = 2; i <= n; i++)
	{
		int t = i & 1;
		int p = t ^ 1;
		// 清空当前层
		for (int j = 0; j <= b; j++)
		{
			dp[t][j][0] = -INF;
			dp[t][j][1] = -INF;
		}
		for (int j = 0; j <= min(i, b); j++)
		{
			dp[t][j][0] = max(dp[p][j][0], dp[p][j][1]);
			if (j >= 1)
			{
				dp[t][j][1] = max(dp[p][j - 1][1] + u[i], dp[p][j - 1][0]);
			}
		}
	}
	int last = n & 1;
	int ans1 = max(dp[last][b][0], dp[last][b][1]);


	// ==========第二轮DP：强制第1段睡觉（入睡，不计u[1]）==========
	memset(dp, -0x3f, sizeof(dp));
	dp[1 & 1][1][1] = 0; // 1号睡，是入睡起点，不加u[1]

	for (int i = 2; i <= n; i++)
	{
		int t = i & 1;
		int p = t ^ 1;
		for (int j = 0; j <= b; j++)
		{
			dp[t][j][0] = -INF;
			dp[t][j][1] = -INF;
		}
		for (int j = 0; j <= min(i, b); j++)
		{
			dp[t][j][0] = max(dp[p][j][0], dp[p][j][1]);
			if (j >= 1)
			{
				dp[t][j][1] = max(dp[p][j - 1][1] + u[i], dp[p][j - 1][0]);
			}
		}
	}
	last	 = n & 1;
	int ans2 = dp[last][b][0];
	// 如果n也睡觉，代表环形首尾相连，1不再是入睡，补上u[1]
	if (dp[last][b][1] > -INF)
	{
		ans2 = max(ans2, dp[last][b][1] + u[1]);
	}

	cout << max(ans1, ans2) << endl;
	return 0;
}
/*
 * 经验总结：
 * - 容易错的地方：环形 DP 若用倍长数组，同一小时（位置 i 与 i+N）会被重复选中，答案偏大；
 *   正确做法是不倍长，在 1 号小时处断环分类。
 * - 关键结论/技巧：断环分类两遍 DP —— 第一遍 1 号不睡（环彻底退化为线性）；第二遍 1 号睡，
 *   把它当作某段小睡的起点（收益 0），最后若 N 号也睡，说明该段跨越了 N→1 边界，补 +u[1]
 *   （对应题面"在时间 N 和时间 1 睡觉，得时间 1 的效用值"）。取两遍最大值。
 * - 复杂度：O(N·B)，滚动数组 O(B)。
 */