// Problem URL: https://www.luogu.com.cn/problem/P3128
// Finish Time: 2026/10/4 12:48:49 AC
// Start Time: 2026/10/3 11:57:02

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e4 + 4;

int			n, k, logn, ans = INT_MIN;
vector<int> g[MAXN];
int			dep[MAXN], d[MAXN], anc[MAXN][20], s[MAXN];

void add_edge(int u, int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs_depth(int u, int f)
{
	for (auto v : g[u])
	{
		if (v == f)
			continue;
		anc[v][0] = u;
		d[v]	  = d[u] + 1;
		dfs_depth(v, u);
	}
}

void init()
{
	for (int j = 1; j <= logn; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	for (int i = logn; i >= 0; i--)
		if (dep[anc[u][i]] >= dep[v])
			swap(u, anc[u][i]);
	if (u == v)
		return u;
	for (int i = logn; i >= 0; i--)
		if (anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

void dfs(int u, int f)
{
	for (auto v : g[u])
	{
		if (v == f)
			continue;
		dfs(v, u);
		d[u] += d[v];
	}
	ans = max(ans, d[u]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	logn = ceil(log2(n));
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
	d[1] = 1, dfs_depth(1, 0);
	init();
	while (k--)
	{
		int u, v;
		cin >> u >> v;
		int r = LCA(u, v), f = anc[r][0];
		d[u]++, d[v]++, d[r]--, d[f]--;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}