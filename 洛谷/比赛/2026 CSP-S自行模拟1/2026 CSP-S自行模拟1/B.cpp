// Problem URL: https://www.luogu.com.cn/contest/365930
// Finish Time: 2026/10/18 11:54:33 AC
// Start Time: 2026/10/18 10:56:48

#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 5;

int n, k, a[MAXN], fa[MAXN];

int dfs(int u, int v)
{
	if (u == 0)
		return -1;
	if (__gcd(a[u], a[v]) > 1)
		return u;
	else
		return dfs(fa[u], v);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		fa[y] = x;
	}
	while (k--)
	{
		int op, u, au;
		cin >> op >> u;
		switch (op)
		{
		case 1:
			cout << dfs(fa[u], u) << '\n';
			break;
		case 2:
			cin >> au;
			a[u] = au;
		};
	}
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：沿 fa 暴力爬祖先，单次查询 O(树高)，最坏 O(n*k)，n=2e5 会被卡；
 *   本场数据弱才 AC，正式赛应换做法（按质因子分组 / 并查集维护最近合法祖先）。
 * - 关键结论/技巧：先判 gcd>1 再向上跳，找不到返回 -1。
 */