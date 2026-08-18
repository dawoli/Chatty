// Problem URL: https://www.luogu.com.cn/problem/P7224
// Finish Time: 2026/8/18 13:50:20 AC
// Start Time: 2026/8/18 13:13:10
// Category: 计数 DP（分组背包） / 容斥

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MOD  = 998244353;
const int		  MAXA = 1e6 + 1;

int cnt[MAXA]; // cnt[v]: 值为 v 的元素个数
ll	fac[MAXA]; // 阶乘
ll	inv[MAXA]; // 阶乘逆元
ll	dp[MAXA];  // dp[j]: 只用 [2, m] 里的元素，凑出积恰为 j 的子集数

ll pow_mod(ll a, ll b)
{
	ll r = 1;
	while (b > 0)
	{
		if (b & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return r;
}

ll C(int c, int t)
{
	if (t < 0 || t > c)
		return 0;
	return fac[c] * inv[t] % MOD * inv[c - t] % MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		++cnt[x];
	}
	int one = cnt[1];

	// 阶乘 / 逆元阶乘预处理（方案 A）
	fac[0] = 1;
	for (int i = 1; i <= MAXA - 1; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	inv[MAXA - 1] = pow_mod(fac[MAXA - 1], MOD - 2);
	for (int i = MAXA - 1; i >= 1; --i)
		inv[i - 1] = inv[i] * i % MOD;

	dp[1] = 1; // 空集，积为 1

	for (int v = 2; v <= m; v++)
	{
		if (!cnt[v]) continue;
		for (int k = m / v; k >= 1; k--)
		{
			if (dp[k] == 0) continue;
			ll p = v;
			for (int t = 1; t <= cnt[v] && p * k <= m; ++t, p *= v)
				dp[p * k] = (dp[p * k] + C(cnt[v], t) * dp[k]) % MOD;
		}
	}

	// 答案 = 2^n - 2^one * sum(dp[1..m])
	ll ans = pow_mod(2, n);
	ll leq = 0;
	for (int j = 1; j <= m; ++j)
		leq = (leq + dp[j]) % MOD;
	ans = (ans - pow_mod(2, one) * leq % MOD + MOD) % MOD;
	cout << ans << endl;

	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：
 *   数组 off-by-one 越界（访问下标 MAXA）：样例能过不代表没 UB，评测机可能错。
 *   分组背包 k 必须从大到小，否则同一组被重复使用导致重复计数。
 *   转移边界含旧积 k：v^t * k <= m，不是 v^t <= m。
 *   v^t 用 long long 迭代维护，勿用 pow（浮点精度 + 慢）。
 * - 关键结论/技巧：
 *   "积 > m" 无上限难数，容斥改数"积 <= m"：答案 = 2^n - 2^one * sum(dp)。
 *   值为 1 单独处理（乘 2^one）；值 > m 进不了积 <= m 子集。
 *   多重集按值分组 + 组合数系数 C(cnt[v], t)，把 O(nm) 压成 O(m ln m)。
 * - 复杂度：时间 O(m ln m)（调和级数），空间 O(m)。
 */
