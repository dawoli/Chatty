#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c[N];
int dis[N];
bool vis[N];
int f[N];
struct Node {
	int u,v,w;
} g[N];
int find(int u)
{
	if (f[u] == u)
	{
		return u;
	}
	return f[u] = find(f[u]);
}
bool cmp(Node x, Node y)
{
	return x.w < y.w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i = 1; i <= m; i++)
	{
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for (int i = 1; i <= k; i++)
	{
		cin>>c[i];
		int u = m + i;
		for (int v = 1; v <= n; v++)
		{
			int d;
			cin>>d;
			g[m + (i - 1) * n + v].u = u;
			g[m + (i - 1) * n + v].v = v;
			g[m + (i - 1) * n + v].w = d;
		}
	}
	int t = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int u = 1; u <= n; u++)
		{
			for (int v = u + 1; v <= n; v++)
			{
				int nd = g[m + (i - 1) * n + u].w + g[m + (i - 1) * n + v].w + c[i];
				g[m + k * n + ++t].u = u;
				g[m + k * n + t].v = v;
				g[m + k * n + t].w = nd;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	sort(g + 1, g + m + n * k + t + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= m + n * k + t + 1; i++)
	{
		int u = g[i].u;
		int v = g[i].v;
		int d = g[i].w;
		if (find(u) != find(v))
		{
			if (m < u && u <= m + n * t)
			{
				continue;
			}
			f[find(u)] = find(v);
			ans += d;
		}
	}
	cout<<ans;
	return 0;
}
