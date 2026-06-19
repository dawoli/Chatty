#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int from, to, w;
	friend bool operator<(edge a, edge b)
	{
		if (a.w == b.w)
			return a.from < b.from;
		return a.w < b.w;
	}
};
edge g[2000005];
int fa[1000005];
int find(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void add(int a, int b)
{
	fa[find(a)] = find(b); 
	return;
}
int ind = 0;
int vis[1000005];
int ans = 0;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; 
		cin >> u >> v >> w;
		ind++;
		g[ind].from = u;
		g[ind].to = v;
		g[ind].w = w;
	}
	if (k != 0)
	{
		for (int i = n + 1; i <= n + k; i++)
		{
			int u;
			cin >> u;
			for (int j = 1; j <= n; j++)
			{
				int u = i;
				int v = j;
				int w;
				cin >> w;
				if (w == 0)
					fa[i] = j;
				ind++;
				g[ind].from = u;
				g[ind].to = v;
				g[ind].w = w;
			}
		}
	} 
	sort(g + 1, g + ind + 1);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	long long ans = 0;
	long long compns = n;
	for (int i = 1; i <= m; i++)
	{
		if (compns == 1)
			break;
		if (find(g[i].from) != find(g[i].to))
		{
			ans += g[i].w;
			add(g[i].from, g[i].to);
			compns--;
		}
	}
	cout << ans;
	return 0;
}
