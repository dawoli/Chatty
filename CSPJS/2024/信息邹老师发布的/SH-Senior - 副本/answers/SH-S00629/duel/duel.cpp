#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MX = 1e5 + 100;
ll n, r[MX], cnt[MX], sum[MX];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);

	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> r[i];
		++cnt[r[i]];
	}
	sort(r + 1, r + n + 1);
	ll t = unique(r + 1, r + n + 1) - r - 1;
	r[t + 1] = 0;
	for (ll i = t; i >= 1; --i) {
		sum[r[i]] = sum[r[i + 1]] + cnt[r[i]];
	}
	ll ans = 0, used = 0;
	for (ll i = 1; i <= t; ++i) {
		used = max(0ll, used - cnt[r[i]]);
		ll x = min(max(0ll, sum[r[i + 1]] - used), cnt[r[i]]);
		used += x;
		ans += cnt[r[i]] - x;
	}
	cout << ans << '\n';

	return 0;
}

