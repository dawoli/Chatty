#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100010;
ll n, m, k, x[5], a[N], a1[N], c[N], p[N], p1[N]; char d[30][N];
void solve()
{
	ll ret = 0;
	scanf("%lld%lld%lld%lld", &x[0], &x[1], &x[2], &x[3]);
	for (ll i = 1; i <= n; i++) a[i] = a1[i] ^ x[i%4];
	for (ll i = 1; i <= m; i++)
	{
		for (ll j = 1; j <= c[i]; j++) p[j] = j;
		ll tot = c[i], r = 1;
		while (tot > 1)
		{
			for (ll j = 1; j <= tot / 2; j++)
				if (d[r][j] == '0') p1[j] = (a[p[(j<<1LL)-1]] >= r ? p[(j<<1LL)-1] : p[j<<1LL]);
				else p1[j] = (a[p[j<<1LL]] < r ? p[(j<<1LL)-1] : p[j<<1LL]);
			tot >>= 1, r++;
			for (ll j = 1; j <= tot; j++) p[j] = p1[j];
		} ret ^= (i * p[1]);
	} printf("%lld\n", ret);
}

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) scanf("%lld", &a1[i]);
	for (ll i = 1; i <= m; i++) scanf("%lld", &c[i]);
	for (ll i = 30; i >= 0; i--)
		if ((1LL << i) < n) { k = i + 1; break; }
	for (ll i = 1; i <= k; i++) scanf("%s", d[i] + 1);
	ll T; scanf("%lld", &T);
	while (T--) solve();
	return 0;
}
