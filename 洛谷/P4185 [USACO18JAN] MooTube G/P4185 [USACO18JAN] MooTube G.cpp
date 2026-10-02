// Problem URL: https://www.luogu.com.cn/problem/P4185
// Finish Time: 2026/10/2 11:50:21 AC
// Start Time: 2026/9/29 16:41:43

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 1e5 + 5;

int n, Q, ans[MAXN];

struct Relation
{
	int u, v, w;
} r[MAXN];

bool operator<(const Relation &a, const Relation &b)
{
	return a.w < b.w;
}

struct Question
{
	int k, v, id;
} q[MAXN];

bool operator<(const Question &a, const Question &b)
{
	return a.k > b.k;
}

int fa[MAXN], sz[MAXN]; // dsu

auto init()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
}

int find(int x)
{ return fa[x] == x ? x : fa[x] = find(fa[x]); }

auto merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	fa[x] = y;
	sz[y] += sz[x];
	return true;
}

auto unionn(int x)
{ return sz[find(x)]; }

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> Q;
	for (int i = 1; i < n; i++)
		cin >> r[i].u >> r[i].v >> r[i].w;
	for (int i = 1; i <= Q; i++)
	{
		cin >> q[i].k >> q[i].v;
		q[i].id = i;
	}
	sort(r + 1, r + n);
	sort(q + 1, q + Q + 1);
	init();
	auto *le = r + n;
	for (int i = 1; i <= Q; i++)
	{
		auto e = lower_bound(r + 1, r + n + 1, Relation{0, 0, q[i].k});
		if (e == r + n + 1)
		{
			ans[q[i].id] = 0;
			continue;
		}
		for (auto *i = e; i != le; i++)
			merge(i->u, i->v);
		le			 = e;
		ans[q[i].id] = unionn(q[i].v) - 1;
	}
	for (int i = 1; i <= Q; i++)
		cout << ans[i] << endl;
	return 0;
}

/*
 * 经验总结：
 * - 离线按相关度阈值从大到小处理询问，逐步合并权值不小于阈值的边。
 * - 每次答案是起点所在连通块大小减一；边界条件是题目要求 w >= k。
 * - 复杂度：O((n + Q) log n + n alpha(n))，空间 O(n + Q)。
 */