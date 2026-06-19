#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 106, mod = 998244353;
int n, m, c[N], s[N], f[N][N][N], g[N];
int fac[N], inv[N], ifac[N];
string str;

inline int C(int n, int m) {
	return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read(), cin >> str;
	for (int i = 1; i <= n; ++i) c[i] = read(), ++s[c[i]];
	for (int i = n - 1; i >= 0; --i) s[i] += s[i + 1];
	fac[0] = ifac[0] = 1;
	fac[1] = ifac[1] = inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	}
	int ans = 0;
	for (int t = m; t <= n; ++t) {
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= min(i, t); ++j)
				for (int k = j; k <= min(i, t); ++k)
					f[i][j][k] = f[i - 1][j][k];
			if (str[i - 1] == '1') {
				for (int j = 0; j <= min(i, t); ++j)
					for (int k = j; k <= min(i, t); ++k) {
						f[i][j + 1][k + 1] = (f[i][j + 1][k + 1] + 1ll * f[i - 1][j][k] * max(s[i - j] - t + k + 1, 0)) % mod;
						f[i][j][k + 1] = (f[i][j][k + 1] + 1ll * (mod - f[i - 1][j][k]) * max(s[i - j] - t + k + 1, 0)) % mod;
					}
			}
		}
		for (int j = m; j <= n; ++j) {
			ans = (ans + 1ll * f[n][j][t] * fac[n - t]) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}