// Problem URL: https://www.luogu.com.cn/problem/P15261 [USACO26JAN2] Lexicographically Smallest Path G
// Finish Time: 2026/10/24 12:46:47 WA 8pts 特殊性质1
// Start Time: 2026/10/24 12:22:19

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 2e5 + 5;

int						 n, m, dis[MAXN];
unordered_map<int, char> e[MAXN];

void add_edge(int u, int v, int w)
{
	auto it1 = e[u].find(v);
	if (it1 == e[u].end())
		e[u][v] = w;
	else if (w < it1->second)
		it1->second = w;
	auto it2 = e[v].find(u);
	if (it2 == e[v].end())
		e[v][u] = w;
	else if (w < it2->second)
		it2->second = w;
}

void all_a()
{
	fill(dis + 1, dis + n + 1, -1);
	queue<int> q;
	dis[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (const auto i : e[u])
		{
			const int v = i.first;
			if (dis[v] != -1)
				continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}

void Main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		e[i].clear();
	bool al_a = true;
	for (int i = 1; i <= m; i++)
	{
		int	 u, v;
		char c;
		cin >> u >> v >> c;
		add_edge(u, v, c);
		if (c != 'a')
			al_a = false;
	}
	if (al_a)
		all_a();
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		Main();
	}
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：只做了全 a 的特殊性质；非全 a 时 dis 没有重置，输出的是上一组残留值。
 * - 关键结论/技巧：字典序最短路要按字符逐层 BFS，每层只沿最小字符扩展；
 *   最优前缀上能回到同层（同字符环）则答案为 -1。
 * - 复杂度：正解 O(N+M)
 */