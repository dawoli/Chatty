#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 10050, M = 1100010, K = 15;

int n, m, k;
int p[N], sz[N];
struct Edges
{
	int a, b;
	LL w;
	int id;
	bool operator < (const Edges &W)
	{
		return w < W.w; 
	}
}ed[M];
struct Vill
{
	LL c;
	LL w[N];
	bool operator < (const Vill &V)
	{
		return c > V.c; 
	}
}vl[K];
int ced;
int l[K], r[K];
bool vis[M];
LL ans = 2e18;
bool flag = true;

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++ ) scanf("%d%d%lld", &ed[i].a, &ed[i].b, &ed[i].w), ed[i].id = i;
	ced = m;	
	
	for (int i = 1; i <= k; i ++ )
	{
		scanf("%lld", &vl[i].c);
		bool vias = false;
		for (int j = 1; j <= n; j ++ ) 
		{
			scanf("%lld", &vl[i].w[j]);
			if (!vl[i].w[j]) vias = true;
		}
		if (vl[i].c || !vias) flag = false;
	}
		
	sort(vl + 1, vl + 1 + k);
		
	if (flag)
	{
		int lt = k;
		while (lt && vl[lt].c == 0)
		{
			for (int j = 1; j <= n; j ++ )
				ed[ ++ ced] = {n + lt, j, vl[lt].w[j]}, ed[ced].id = ced;
			lt -- ;
		}
		n += k;
		k = lt;
	}
	for (int i = 1; i <= ced; i ++ ) vis[i] = true;
	
	for (int i = 1; i <= k; i ++ )
	{
		l[i] = ced + 1;
		for (int j = 1; j <= n; j ++ )
			ed[ ++ ced] = {n + i, j, vl[i].w[j]}, ed[ced].id = ced;
		r[i] = ced;
	}
	
	sort(ed + 1, ed + 1 + ced);
	for (int s = 0; s < (1 << k); s ++ )
	{
		for (int j = 0; j < k; j ++ )
			for (int t = l[j + 1]; t <= r[j + 1]; t ++ )
				vis[t] = (s >> j & 1);
		
		LL res = 0;	
		for (int j = 0; j < k; j ++ )
			if (s >> j & 1)
				res += vl[j + 1].c;
		for (int i = 1; i <= n + k; i ++ ) p[i] = i;
		for (int i = 1; i <= ced; i ++ )
		{
			if (!vis[ed[i].id]) continue;
			int a = ed[i].a, b = ed[i].b, w = ed[i].w;
			a = find(a), b = find(b);
			if (a == b) continue;
			res += w;
			p[a] = b;
		}
		
		ans = min(ans, res);
	}
	
	cout << ans;
	return 0;
}
