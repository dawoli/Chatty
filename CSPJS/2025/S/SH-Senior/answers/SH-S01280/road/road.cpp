#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 20009;
const ll M = 2000009;
ll n, m, k, fa[N], c[19], a[19][N], id[M], v[2000];

struct Edge
{
	ll u, v, w;
} e[M];

bool cmp(const ll &x, const ll &y)
{
	return e[x].w < e[y].w;
}

ll root(ll x)
{
	return fa[x] == x ? x : fa[x] = root(fa[x]);
}

void unite(ll x, ll y)
{
	fa[root(x)] = root(y);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ll ans = 100000000000000;
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1;i <= m;i++)
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		e[i] = {u, v, w};
	}
	for (ll i = 1;i <= k;i++)
	{
		scanf("%lld", &c[i]);
		for (ll j = 1;j <= n;j++) scanf("%lld", &a[i][j]);
	}
	for (ll i = 1;i < M;i++) id[i] = i;
	for (ll _ = 0;_ < 1 << k;_++)
	{
		if (v[_]) continue;
		for (ll i = 1;i <= n + k;i++) fa[i] = i;
		ll tot = m, sum = 0;
		for (ll i = 1;i <= k;i++) if ((1 << i - 1) & _)
		{
			sum += c[i];
			for (ll j = 1;j <= n;j++) e[++tot] = {n + i, j, a[i][j]};
		}
		sort(id + 1, id + 1 + tot, cmp);
		ll cnt = n;
		for (ll i = 1;i <= tot;i++)
		{
			if (cnt == 1) break;
			ll u = e[id[i]].u, v = e[id[i]].v;
			if (root(u) == root(v)) continue;
			sum += e[id[i]].w;
			if (fa[u] <= n) cnt--;
			unite(u, v);
		}
		if (sum > ans) for (ll __ = 1;__ < 1 << k;__++) v[_ | __] = 1;
		ans = min(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}

