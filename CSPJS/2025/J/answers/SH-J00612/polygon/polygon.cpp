#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define ll long long
int n, a[5003], mx;
const ll p = 998244353;

ll ksm(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % p;
		y >>= 1;
		x = x * x % p;
	}
	return res;
}

ll C(ll n, ll m) {
	ll res = 1;
	if (n == m) return 1;
	for (int i = 1; i <= n; i++)
		res = res * m % p, m--;
	for (int i = 2; i <= n; i++)
		res = res * ksm(i, p - 2) % p;
	return res;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
	if (n == 3) {
		sort(a + 1, a + 4);
		if (a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	if (mx == 1) {
		ll ans = 0;
		for (int i = 3; i <= n; i++)
			ans = (ans + C(i, n)) % p;
		printf("%lld\n", ans);
	}
	return 0;
}
