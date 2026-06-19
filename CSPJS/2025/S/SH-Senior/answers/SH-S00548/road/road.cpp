#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 2000010, K = 16, W = 1000010;

int n, m, k, f[N], sz[N], c[K], a[K][N], u[W], v[W], w[W], id = 0;
long long tot = 1e18;
struct edge
{
	int u, v, w;
}e[M];

int find(int x)
{
	if (x != f[x])
	{
		f[x] = find(f[x]);
	}
	return f[x];
}

int read()
{
	int sgn = 0, ret = 0, ch = getchar();
	while (!isdigit(ch))
	{
		sgn |= (ch == '-');
		ch = getchar();
	}
	while (isdigit(ch))
	{
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return sgn ? -ret : ret;
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= m; i ++ )
	{
		u[i] = read();
		v[i] = read();
		w[i] = read();
	}
	for (int j = 1; j <= k; j ++ )
	{
		c[j] = read();
		for (int i = 1; i <= n; i ++ )
		{
			a[j][i] = read();
		}
	}
	for (int i = 0; i < (1 << k); i ++ )
	{
		for (int j = 1; j <= n + k; j ++ )
		{
			f[j] = j;
			sz[j] = 1;
		}
		id = 0;
		long long ans = 0;
		for (int j = 1; j <= m; j ++ )
		{
			e[ ++ id] = {u[j], v[j], w[j]};
		}
		int idx = n, kk = 0;
		for (int j = 0; j < k; j ++ )
		{
			if (i >> j & 1)
			{
				ans += c[j + 1];
				idx ++ ;
				kk ++ ;
				for (int t = 1; t <= n; t ++ )
				{
					e[ ++ id] = {idx, t, a[j + 1][t]};
				}
			}
		}
		sort(e + 1, e + id + 1, cmp);
		int cnt = 0;
		for (int j = 1; j <= id; j ++ )
		{
			int a = find(e[j].u), b = find(e[j].v);
			if (a == b) continue;
			if (sz[a] > sz[b])
			{
				swap(a, b);
			}
			f[a] = b;
			sz[b] += sz[a];
			ans += e[j].w;
			cnt ++ ;
			if (ans >= tot || cnt == n + kk - 1)
			{
				break;
			}
		}
		tot = min(tot, ans);
	}
	printf("%lld\n", tot);
	
	return 0;
}
