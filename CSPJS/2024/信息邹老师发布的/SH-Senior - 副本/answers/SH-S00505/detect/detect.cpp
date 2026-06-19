#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100010, M = 3010;
struct che { ll d, v, a; }s[N];
ll n, m, l, v, flagA, flagB, flagC, p[N], f[M][M], f1[N], f2[N], x[N];
double disv(ll v, ll a, ll s, ll t) { return sqrt(v * v + 2 * a * (t - s)); }
void solveA()
{
	ll ret = 0;
	for (ll i = 1; i <= n; i++)
		if (s[i].v > v)
		{
			ll pos = lower_bound(p + 1, p + m + 1, s[i].d) - p;
			if (pos <= m) ret++;
		}
	if (ret > 0) printf("%lld %lld\n", ret, m - 1);
	else printf("%lld %lld\n", ret, m);
}
void solveB()
{
	memset(x, 0, sizeof(x));
	ll ret = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll pos = lower_bound(p + 1, p + m + 1, s[i].d) - p, flag = 0;
		for (ll j = pos; j <= m; j++)
			if (disv(s[i].v, s[i].a, s[i].d, p[j]) > v) { x[i] = j, flag = 1; break; }
		ret += flag;
	}
	if (ret > 0) printf("%lld %lld\n", ret, m - 1);
	else printf("%lld %lld\n", ret, m);
}
void solve()
{
	scanf("%lld%lld%lld%lld", &n, &m, &l, &v), flagA = 1, flagB = 1, flagC = 1;
	for (ll i = 1; i <= n; i++) scanf("%lld%lld%lld", &s[i].d, &s[i].v, &s[i].a), flagA &= (s[i].a == 0), flagB &= (s[i].a > 0), flagC &= (s[i].a < 0);
	for (ll i = 1; i <= m; i++) scanf("%lld", &p[i]);
	if (flagA) solveA();
	else if (flagB) solveB();
	else
	{
		memset(f, 0, sizeof(f)), memset(f2, 0, sizeof(f2));
		ll ret = 0, mx = 0;
		for (ll i = 1; i <= n; i++)
		{
			ll pos = lower_bound(p + 1, p + m + 1, s[i].d) - p, flag = 0;
			for (ll j = pos; j <= m; j++)
				if (disv(s[i].v, s[i].a, s[i].d, p[j]) > v) f[i][j] = 1, flag = 1;
			ret += flag, f2[i] = flag;
		}
		for (ll i = 0; i < (1LL << m); i++)
		{
			memset(f1, 0, sizeof(f1));
			ll flag = 1, cnt = 0;
			for (ll j = 1; j <= m; j++)
				if ((1LL << (j-1)) & i)
				{
					for (ll k = 1; k <= n; k++) f1[k] |= f[k][j];
					cnt++;
				}
			for (ll j = 1; j <= n; j++)
				if (f2[j] && !f1[j]) { flag = 0; break; }
			if (flag) mx = max(mx, m - cnt);
		} printf("%lld %lld\n", ret, mx);
	}
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ll T; scanf("%lld", &T);
	while (T--) solve();
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

*/
