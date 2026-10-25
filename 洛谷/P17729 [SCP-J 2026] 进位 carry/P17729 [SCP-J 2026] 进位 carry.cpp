// Problem URL: https://www.luogu.com.cn/problem/P17729 [SCP-J 2026] 进位 carry
// Finish Time: 2026/10/20 17:22:11 AC
// Start Time: 2026/10/20 16:58:06

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define cnt(x) __builtin_popcountll((x))
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MOD	= 998244353;
constexpr int		   MXAN = 6e6 + 5;

int t, n, a[MXAN], s1[MXAN], s2[MXAN], sdp[MXAN], dp[MXAN];

int C(int l, int r)
{
	return s2[r] - s2[l - 1] - (cnt(s1[r] - s1[l - 1]));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(sdp, 0, sizeof(sdp));
		s1[0] = 0;
		s2[0] = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i], s1[i] = s1[i - 1] + a[i];
		for (int i = 1; i <= n; i++)
			s2[i] = s2[i - 1] + cnt(a[i]);
		int l = 1, r = 1, R = 1, ans = 0;
		while (R <= n)
		{
			while (l < R && C(l, R) > 1)
				l++;
			while (r < R && C(r, R) > 0)
				r++;
			dp[R]  = (1 + sdp[r - 1] - sdp[l - 1] + MOD) % MOD;
			sdp[R] = (sdp[R - 1] + dp[R] + MOD) % MOD;
			R++;
		}
		for (int i = 1; i <= n; i++)
			ans = (ans + dp[i]) % MOD;
		cout << ans << endl;
	}
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：前缀和 s1 到 2e15 要 long long；dp/sdp/l,r 每组都要重置；区间是 [l,r-1]。
 * - 关键结论/技巧：C(l,r)=Σpopcount(a_i)-popcount(Σa_i)；C(j,R) 随 j 单调不增、随 R 单调不减，
 *   双指针找出 C=1 的左端点区间，再用 dp 前缀和 O(1) 转移。
 * - 复杂度：每组 O(n)
 */