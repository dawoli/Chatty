#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const ll N = 5005;
ll n, a[N];
ll qpow(ll x, ll y) {
	ll res = 1ll;
	while (y) {
		if (y & 1ll) res = res * x % mod;
		x = x * x % mod; y >>= 1ll;
	}
	return res % mod;
}
void solvebf() {
	ll ans = 0;
	for (int i = 0; i < (1 << n); i ++) {
		ll mxnum = -1, smnum = 0, cnt = 0;
		for (int j = 0; j < n; j ++)
			if ((i >> j) & 1) {
				mxnum = max(mxnum, a[j + 1]);
				smnum += a[j + 1];
				cnt ++;
			}
		if (cnt >= 3 && smnum > 2 * mxnum)
			ans = (ans + 1) % mod;
	}
	cout << ans << "\n";
}
void solvea1() {
	ll ans = qpow(2ll, n);
	ans = (ans - 1 - n + mod) % mod;
	ans = (ans - (1ll * n * (n - 1) / 2 % mod) + mod) % mod;
	cout << ans << "\n";
}
ll dp[10004];
void solveak() {
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		ll now = qpow(2ll, i - 1);
		for (int j = 0; j <= a[i]; j ++) {
			now = (now - dp[j] + mod) % mod;
		}
		ans = (ans + now) % mod;
		for (int j = 10000; j >= a[i]; j --)
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
	}
	cout << ans << "\n";
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	bool sub = true;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != 1) sub = false;
	}
	if (n <= 20) {
		solvebf();
	} else if (sub) {
		solvea1();
	} else {
		solveak();
	}
	return 0;
}
