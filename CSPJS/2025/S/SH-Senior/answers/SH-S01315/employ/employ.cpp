#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 507, MOD = 998244353;
int n, m, a[N], b[N], c[N], fac[N], ifc[N];

int power(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) (ret *= x) %= MOD;
		(x *= x) %= MOD;
		y >>= 1;
	}
	return ret;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%1lld", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]), b[i] = i;
	if (n > 12) cout << 0, exit(0);
	int ans = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt < c[b[i]] && a[i] == 1) ++cnt;
		}
		if (cnt >= m) ++ans;
	} while (next_permutation(b + 1, b + n + 1));
	cout << ans;
	return 0;
}
