// Problem URL: https://www.luogu.com.cn/contest/365930
// Finish Time: 2026/10/18 12:33:56 AC
// Start Time: 2026/10/18 10:56:48

#include <bits/stdc++.h>
#define a first
#define s second
using namespace std;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;

pii v[MAXN];
int n, sum[MAXN], f[MAXN], b[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].s;
	for (int i = 1; i <= n; i++)
		cin >> v[i].a;
	sort(v + 1, v + n + 1, greater<pii>());
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + v[i].a;
		f[i]   = max(f[i - 1], 2 * v[i].s);
	}
	for (int i = n; i >= 1; i--)
		b[i] = max(b[i + 1], 2 * v[i].s + v[i].a);
	for (int i = 1; i <= n; i++)
		cout << max(sum[i] + f[i], sum[i - 1] + b[i]) << '\n';
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：2*s 只对最远那一户计一次；排序后 a 的前缀和要配 s 的前缀最大值。
 * - 关键结论/技巧：最优解只有两类——全取 a 前 k 大，或用后面更远的户替换掉第 k 大。
 * - 复杂度：O(n log n)
 */