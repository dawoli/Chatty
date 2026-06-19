#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200010;
ll n, a[N], col[N];
void solve()
{
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
	ll mx = 0;
	for (ll i = 0; i < (1LL << n); i++)
	{
		ll cnt = 0; memset(col, 0, sizeof(col));
		for (ll j = 0; j < n; j++)
			if ((1LL << j) & i) col[j] = 1;
		for (ll j = 0; j < n; j++)
			for (ll k = j - 1; k >= 0; k--)
				if (col[j] == col[k] && a[j] == a[k]) { cnt += a[j]; break; }
		mx = max(mx, cnt);
	} printf("%lld\n", mx);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ll T; scanf("%lld", &T);
	while (T--) solve();
	return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

*/
