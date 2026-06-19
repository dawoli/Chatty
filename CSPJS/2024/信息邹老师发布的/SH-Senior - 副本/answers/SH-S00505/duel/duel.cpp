#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100010;
ll n, a[N]; map<ll, ll> mp;
void solve()
{
	scanf("%lld", &n); ll mx = 0;
	for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (ll i = 1; i <= n; i++) mp[a[i]]++;
	for (auto it : mp) mx = max(mx, it.second);
	printf("%lld\n", mx);
}

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ll T = 1;
	while (T--) solve();
	return 0;
}
