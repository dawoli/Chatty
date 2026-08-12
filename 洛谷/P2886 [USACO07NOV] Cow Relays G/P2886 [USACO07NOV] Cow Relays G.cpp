// Problem URL: https://www.luogu.com.cn/problem/P2886
// Finish Time: 2026/8/5 11:12:52 AC
// Finish Time: 2026/8/4 15:42:46 MLE
// Start Time: 2026/8/4 15:30:57

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long			 ll;
typedef tuple<int, int, int> tiii;
constexpr int				 MAXN = 1e6 + 6;
constexpr int				 MAXV = 102;
constexpr int				 MAXP = 1e3 + 3;

int			 n, t, s, e;
ll			 dis[2][MAXP];
vector<tiii> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> t >> s >> e;
	for (int i = 1; i <= t; i++)
	{
		int w, u, v;
		cin >> w >> u >> v;
		p.push_back({w, u, v});
		p.push_back({w, v, u});
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[0][s] = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(dis[i & 1], 0x3f, sizeof(dis[i & 1]));
		for (auto x : p)
		{
			int w = get<0>(x), u = get<1>(x), v = get<2>(x);
			dis[i & 1][v] = min(dis[i & 1][v], dis[(i - 1) & 1][u] + w);
		}
	}
	cout << dis[n & 1][e];
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：
 *   - 数组两维量纲别混：二维按点标号索引(≤1000)，不能按边数上限 MAXN 开；
 *     每层 memset 清整行，行宽决定总耗时(MAXN 版清 8TB，MAXP 版清 8GB)。
 *   - 全量存 N 层会 MLE：转移只依赖上一层，必须滚动数组。
 *   - 每层开算前先 fill 成 INF，否则两层前残留污染 min 聚合。
 * - 关键结论/技巧：
 *   - "恰好 N 条边的最短路" = 分层 DP，dis[j][v] = min(dis[j-1][u]+w)；
 *     两层 + j&1 轮换读写天然错开。
 *   - 正解为 (min,+) 半环矩阵快速幂 O(V^3 logN)，V≤2T≤200。
 * - 复杂度：时间 O(NT)，空间 O(V)。
 */