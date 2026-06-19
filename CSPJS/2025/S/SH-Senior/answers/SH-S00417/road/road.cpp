#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
int n, m, k, ans = LONG_LONG_MAX, c[N], fa[N];
bool a[15], vis[N];
//struct Node
//{
//	int v, w;
//};
struct Edge
{
	int u, v, w;
};
vector<Edge> e;
//vector<Node> g[N + 10];
bool cmp(const Edge & A, const Edge & B)
{
	return A.w < B.w;
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
bool check(int x)
{
	return x > n && (!a[x - n]);
}
int kru(int cnt)
{
	int cost = 0;
	for(int i = 1; i <= n + k; i++)
		fa[i] = i;
	int j = 0;
	for (int i = 1; i < n + cnt; i++)
	{
		while (check(e[j].u) || check(e[j].v) || find(e[j].u) == find(e[j].v))
			j++;
		fa[find(e[j].u)] = find(e[j].v);
		cost += e[j].w;
	}
	return cost;
}
void dfs(int x, int ad, int cnt)
{
	if (x == k + 1)
	{
		ans = min(ans, kru(cnt) + ad);
		return;
	}
	a[x] = 1;
	dfs(x + 1, ad + c[x], cnt + 1);
	a[x] = 0;
	dfs(x + 1, ad, cnt);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
//		g[u].push_back({v, w});
//		g[v].push_back({u, w});
		e.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
//			g[i + n].push_back({j, w});
//			g[j].push_back({i + n, w});
			e.push_back({i + n, j, w});
		}
	}
	sort(e.begin(), e.end(), cmp);
	dfs(1, 0, 0);
	cout << ans;
}
// AC
