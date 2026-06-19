#include<bits/stdc++.h>
using namespace std;
#define int long long

struct edge
{
	int u, v, w;
};

bool operator<(edge a, edge b)
{
	return a.w < b.w;
}

const int M = 1000005, N = 110025, K = 1050, KK = 12;
edge b[M], P[N];
int c[N], f[N], f2[N], cr[K], p[KK][N];

inline int find(int x)
{
	if(c[x] == x) return x;
	c[x] = find(c[x]);
	return c[x];
}

inline void merge(int u, int v)
{
	c[u] = v;
}

inline void init()
{
	f2[0] = 1;
	for(int i = 1; i < KK; i++) f2[i] = f2[i - 1] * 2;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0, cnt = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		b[i] = {x, y, z};
	}
	sort(b + 1, b + m + 1);
	for(int i = 1; i <= n; ++i) c[i] = i;
	for(int i = 1; i <= m; ++i)
	{
		int a1 = b[i].u, b1 = b[i].v, d = b[i].w;
		int u = find(a1), v = find(b1);
		if(u == v) continue;
		merge(u, v);
		ans += d; 
		P[++cnt] = {a1, b1, d};
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &f[i]);
		for(int j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}
	init();
	for(int i = 1; i < pow(2, k); ++i)
	{
		int cr = 0, cur = cnt;
		for(int j = 1; j < KK - 1; ++j)
		{
			if(i % f2[j] >= f2[j - 1])
			{
				cr += f[j];
				for(int kk = 1; kk <= n; ++kk) P[++cur] = {n + j, kk, p[j][kk]};
			}
		}
		sort(P + 1, P + cur + 1);
		for(int j = 1; j <= n + k; j++) c[j] = j;
		for(int j = 1; j <= cur; j++)
		{
			int a1 = P[j].u, b1 = P[j].v, d = P[j].w;
			int u = find(a1), v = find(b1);
			if(u == v) continue;
			c[u] = v;
			cr += d;
		}
		ans = min(ans, cr);
	}
	printf("%d", ans);
}
