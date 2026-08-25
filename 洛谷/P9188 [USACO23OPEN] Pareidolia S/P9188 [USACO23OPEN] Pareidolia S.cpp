// Problem URL: https://www.luogu.com.cn/problem/P9188
// Finish Time: 2026/8/22 20:48:34 AC
// Finish Time: 2026/8/22 20:41:53 WA 16pts
// Start Time: 2026/8/22 20:32:12

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 3e5 + 5;

ll	   n, dp[MAXN], pre[7];
ll	   ans = 0;
string s;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++)
	{
		switch (s[i - 1])
		{
		case 'b':
			pre[1] = i;
			break;
		case 'e':
			pre[2] = pre[1];
			pre[6] = pre[5];
			break;
		case 's':
			pre[4] = pre[3]; // 原来这两行是反过来的
			pre[3] = pre[2]; // 导致一个s充当了两个s（把pre[2]换到了pre[4])
			break;			 // 因此调换顺序，遂AC
		case 'i':
			pre[5] = pre[4];
		}
		int j = pre[6];
		dp[i] = (j == 0 ? 0 : dp[j - 1] + j);
		ans += dp[i];
	}
	cout << ans << endl;
	return 0;
}

/*
 * 经验总结：
 * - 题意：令 f(t) = 字符串 t 中最多能组成多少个不重叠的 "bessie" 子序列，
 *   求所有子串 t 的 f(t) 之和。注意是"子序列"且允许重复，不是连续子串计数。
 * - 容易错的地方：case 's' 里 pre[4]、pre[3] 必须"从后往前"更新（先 pre[4]=pre[3] 再 pre[3]=pre[2]），
 *   否则同一个 's' 会同时充当两个 's' 导致错配（此 WA 16pts）。
 * - 关键结论/技巧：pre[1..6] 记录 "bessie" 各前缀作为子序列的"最右匹配起点"。
 *   设 j=pre[6]（右端点 i 处完整 bessie 的最右起点），由于 j 是最右，有
 *   f(s[l..i]) = (l <= j ? 1 + f(s[l..j-1]) : 0)，对 l 累加得 dp[i] = dp[j-1] + j，答案 = Σdp[i]。
 * - 复杂度：O(|s|)；答案可达 O(n^2) 量级，需用 long long。
 */