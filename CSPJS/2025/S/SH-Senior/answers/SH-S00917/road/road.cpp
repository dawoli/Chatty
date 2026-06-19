#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+9;
const int M = 1e6+9;
const int K = 10;
int n,m,k,nPtn,fa[N],c[K],a[N][K],lg[1<<K];
ll f[N][1<<K],g[1<<K];
int root(int x) {return fa[x] == x ? x : (fa[x] = root(fa[x]));}
struct Edge {int u,v,w;} e[M],e2[M];
bool operator < (const Edge&e1, const Edge&e2) {return e1.w < e2.w;}
template <typename _Tp> inline void chkmn(_Tp&x, const _Tp&v) {if (v < x) x = v;}
ll MST()
{
	for (int i = 1; i <= m; ++i) e2[i] = e[i];
	sort(e2 + 1, e2 + m + 1);
	iota(fa + 1, fa + n + k + 1, 1);
	ll ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		int u = e2[i].u,v = e2[i].v,w = e2[i].w;
		if (root(u) == root(v)) continue;
		ans += w;
		fa[root(u)] = root(v);
	}
	return ans;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	nPtn = (1 << k);
	lg[0] = -1;
	for (int p = 1; p < nPtn; ++p) lg[p] = lg[p >> 1] + 1;
	for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + m + 1);
	iota(fa + 1, fa + n + 1, 1);
	ll ans = 0;
	for (int i = 1,j = 1; i <= m; ++i)
	{
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if (root(u) == root(v)) continue;
		ans += w;
		fa[root(u)] = root(v);
		e[j++] = e[i];
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &c[i]);
		for (int u = 1; u <= n; ++u) scanf("%d", &a[u][i]);
	}
	for (int p = 1; p < nPtn; ++p)
	{
		ll sum = 0;
		m = n - 1;
		for (int i = 0; i < k; ++i) if (p >> i & 1)
		{
			sum += c[i];
			for (int u = 1; u <= n; ++u) e[++m] = (Edge){u, n + 1 + i, a[u][i]};
		}
		chkmn(ans, sum + MST());
	}
	printf("%lld\n", ans);
	return 0;
}