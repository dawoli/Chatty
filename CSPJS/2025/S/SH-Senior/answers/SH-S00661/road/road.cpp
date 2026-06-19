#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1e4 + 10, M = 2e6 + 10;

struct edge
{
	int u, v, w;
} e[M];

int n, m, k, tot;
long long ans;
int a[N], f[N];

int find(int x)
{
//	cout << x << endl;
	return (f[x] == 0) ? x : f[x] = find(f[x]);
}

bool cmp(edge x, edge y)
{
	return x.w < y.w;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	tot = m;
	for (int i = 1; i <= k; i++)
	{
		int c;
		cin >> c;
		int p;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0)
			{
				p = i;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			tot++;
			e[tot].u = p, e[tot].v = i, e[tot].w = a[i];
		}
	}
	sort(e + 1, e + tot + 1, cmp);
	for (int i = 1; i <= tot; i++)
	{
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y)
		{
			ans += e[i].w;
			f[x] = y;
		}
	}
	cout << ans << endl;
	return 0;
} 
