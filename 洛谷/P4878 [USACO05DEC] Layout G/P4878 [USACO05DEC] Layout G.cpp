#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;

struct edge
{
	int v, w;
};
vector<edge> e[MAXN];
int			 dis[MAXN], cnt[MAXN];
bitset<MAXN> vis;
queue<int>	 q;

void add_edge(const int &u, const int &v, const int &w)
{
	e[u].push_back({v, w});
}

int n, ml, md, a, b, d;

bool spfa(int n, int s)
{
	memset(dis, 0x3f, (n + 1) * sizeof(int));
	memset(cnt, 0, (n + 1) * sizeof(int));
	while (!q.empty())
		q.pop();
	vis.reset();
	dis[s] = 0, vis[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop(), vis[u] = 0;
		for (auto ed : e[u])
		{
			int v = ed.v, w = ed.w;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n)
					return false;
				if (!vis[v])
					q.push(v), vis[v] = 1;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> ml >> md;

	for (int i = 1; i <= ml; i++)
	{
		cin >> a >> b >> d;
		if (a < b)
			swap(a, b);
		add_edge(b, a, d);
	}
	for (int i = 1; i <= md; i++)
	{
		cin >> a >> b >> d;
		if (b < a)
			swap(a, b);
		add_edge(b, a, -d);
	}

	for (int i = 1; i <= n; i++)
	{
		add_edge(0, i, 0);
	}
	for (int i = 1; i < n; i++)
	{
		add_edge(i + 1, i, 0);
	}

	if (!spfa(n, 0))
		cout << -1;
	else
	{
		spfa(n, 1);
		if (dis[n] == 0x3f3f3f3f)
			cout << -2;
		else
			cout << dis[n];
	}
	return 0;
}

/* 差分约束（Difference Constraints）经验总结

   核心转化公式（最短路形式 dis[v] <= dis[u] + w）：
   约束             ->  最短路形式           ->  建边
   x_B - x_A <= D       x_B <= x_A + D          A --(D)--> B
   x_B - x_A >= D       x_A <= x_B + (-D)       B --(-D)--> A

   注意事项：
   1. 确定方向时，统一化成 x_j - x_i <= c 的形式，边就是 i -> j 权 c
   2. "最多相距 D" 为 ML 边（<=），"至少相距 D" 为 MD 边（>=）
   3. 虚拟源点 0 连所有点（权 0），用于检测整个图的负环
   4. 求 max(x_n - x_1) 等价于求 1 到 n 的最短路
   5. 编号顺序排列约束（本题存在）：pos[i] <= pos[i+1]
	  转化为最短路形式：pos[i] - pos[i+1] <= 0，边为 (i+1) --0--> i
	  注意方向不要搞反（i --0--> i+1 是 pos[i+1] <= pos[i]，反了）
*/