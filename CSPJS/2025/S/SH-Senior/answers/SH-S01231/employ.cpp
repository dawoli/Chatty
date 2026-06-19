#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll n, m, t, ans, pre, cur;
ll a[510];
ll b[510];
ll d[510];
char c[510];
ll f[3][510][510];
ll pos[3][510][510];
ll C[510][510];
ll fac[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[0] = 1;
	for (ll i = 1; i <= 500; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	for (ll i = 0; i <= 500; i++) {
		C[i][0] = 1;
		for (ll j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1] >= mod ? C[i - 1][j] + C[i - 1][j - 1] - mod : C[i - 1][j] + C[i - 1][j - 1]);
		}
	}
	scanf("%lld%lld", &n, &m);
	scanf("%s", c + 1);
	for (ll i = 1; i <= n; i++) {
		a[i] = (c[i] ^ 48);
	}
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &b[i]);
	}
	sort(b + 1, b + n + 1);
	t = 1;
	d[1] = 1;
	for (ll i = 1; i <= n; i++) {
		if (a[i]) {
			t++;
			d[t] = d[t - 1];
		} else {
			d[t]++;
		}
	}
	t--;
	d[t + 1] = n + 1;
	pre = 0;
	cur = 1;
	f[0][0][0] = 1;
	while (pos[0][0][0] < n && b[pos[0][0][0] + 1] < d[1]) {
		pos[0][0][0]++;
	}
	for (ll i = 1; i <= t; i++) {
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= j; k++) {
				if (!f[pre][j][k]) {
					continue;
				}
				f[pre][j][k] %= mod;
				ll s = 0;
				ll x = 0;
				ll y = 0;
				ll r = 0;
				
				s = f[pre][j][k];
				x = 0;
				r = pos[pre][j][k];
				while (r < n && b[r + 1] < d[i + 1] + i - j - 1) {
					r++;
					x++;
				}
				y = 1;
				for (ll l = 0; l <= x && l <= k + 1; l++) {
					f[cur][j + 1][k + 1 - l] += s * C[k + 1][l] % mod * C[x][l] % mod * fac[l] % mod;
					pos[cur][j + 1][k + 1 - l] = r;
				}
				
				s = f[pre][j][k] * (pos[pre][j][k] - (j - k) - (i - 1 - j)) % mod;
				x = 0;
				r = pos[pre][j][k];
				while (r < n && b[r + 1] < d[i + 1] + i - j) {
					r++;
					x++;
				}
				for (ll l = 0; l <= x && l <= k; l++) {
					f[cur][j][k - l] += s * C[k][l] % mod * C[x][l] % mod * fac[l] % mod;
					pos[cur][j][k - l] = r;
				}
				f[pre][j][k] = 0;
			}
		}
		pre = cur;
		cur = 1 - pre;
	}
	for (ll i = m; i <= n; i++) {
		for (ll j = 0; j <= i; j++) {
			if (!f[pre][i][j]) {
				continue;
			}
			ll s = f[pre][i][j] % mod;
			ll x = n - pos[pre][i][j];
			ans += s * C[x][j] % mod * C[j][j] % mod * fac[j] % mod;
			ans %= mod;
		}
	}
	t = 0;
	for (ll i = 1; i <= n; i++) {
		if (!a[i]) {
			t++;
			ans = ans * t % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
