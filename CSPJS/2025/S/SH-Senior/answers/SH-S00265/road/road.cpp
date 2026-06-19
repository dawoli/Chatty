#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k, c[15], fa[10020], ans = 1e18;
struct st
{
	ll u, v, w;
}a[1100005];
bool cmp(st ta, st tb)
{
	return ta.w < tb.w;
}
bool b[15];
ll find(ll ta)
{
	if (fa[ta] == ta) return ta;
	return fa[ta] = find(fa[ta]);
}
vector <ll> vv[15];
void dfs(ll now, ll rec)
{
	if (now == k + 1)
	{
		ll tmp = rec;
		for (ll i = 1; i <= n + k; i++) fa[i] = i;
		for (ll i = 1; i <= m; i++)
		{
			if (a[i].u > n && b[a[i].u - n] == 0) continue;
			if (a[i].v > n && b[a[i].v - n] == 0) continue;
			ll ta = find(a[i].u), tb = find(a[i].v);
			if (ta == tb) continue;
			fa[ta] = tb;
			tmp += a[i].w;
		}
		ans = min(ans, tmp);
		return;
	}
	b[now] = 0;
	dfs(now + 1, rec);
	b[now] = 1;
	dfs(now + 1, rec + c[now]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll tt = 0;
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
	for (ll i = 1; i <= k; i++)
	{
		cin >> c[i];
		tt += c[i];
		for (ll j = 1; j <= n; j++)
		{
			m++;
			a[m].u = n + i;
			a[m].v = j;
			cin >> a[m].w;
		}
	}
	sort(a + 1, a + m + 1, cmp);
	if (tt)	dfs(1, 0);
	else
	{
		ll tmp = 0;
		for (ll i = 1; i <= n + k; i++) fa[i] = i;
		for (ll i = 1; i <= m; i++)
		{
			ll ta = find(a[i].u), tb = find(a[i].v);
			if (ta == tb) continue;
			fa[ta] = tb;
			if (ta > n) vv[ta - n].push_back(a[i].w);
			if (tb > n) vv[tb - n].push_back(a[i].w);
			tmp += a[i].w;
		}
		for (ll i = 1; i <= k; i++)
		{
			if (vv[i].size() == 1) tmp -= vv[i][0];
		}
		ans = tmp;
	}
	cout << ans;
}
