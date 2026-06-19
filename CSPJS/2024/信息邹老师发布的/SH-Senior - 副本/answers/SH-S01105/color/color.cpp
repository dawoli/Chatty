#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 7;

ll n, a[N];

namespace __20pts {
	ll v[N], c[N];
	void solve() {
		memset(v, 0, sizeof v);
		memset(c, 0, sizeof c);
		ll res = 0;
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 1; j <= n; ++j) c[j] = 0;
			for (int j = 0; j < n; ++j) v[j + 1] = i >> j & 1;
			// v[i] = 1 -> red
			int r = 0, b = 0;
			for (int j = 1; j <= n; ++j) {
				if (v[j]) {
					if (r) c[j] = (a[r] == a[j]) * a[j];
				} else {
					if (b) c[j] = (a[b] == a[j]) * a[j];
				}
				v[j] ? r = j : b = j;
			}
			ll sum = 0;
			for (int j = 1; j <= n; ++j) sum += c[j];
			res = max(res, sum);
		}
		printf("%lld\n", res);
	}
}

namespace luck {
	ll f[N][2]; // 1 red; 0 blue
	void solve() {
		memset(f, 0, sizeof f);
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j < i; ++j) {
				f[i][0] = max(f[i][0], f[j][0] + (a[i] == a[j]) * a[i]);
				f[i][0] = max(f[i][0], f[j][1]);
				f[i][1] = max(f[i][1], f[j][1] + (a[i] == a[j]) * a[i]);
				f[i][1] = max(f[i][1], f[j][0]);
			}
		}
		printf("%lld\n", max(f[n][0], f[n][1]));
	}
}

void solve() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	if (n <= 15) __20pts::solve();
	else luck::solve();
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	ll T;
	scanf("%lld", &T);
	while (T--) solve();
	
	return 0;
}

