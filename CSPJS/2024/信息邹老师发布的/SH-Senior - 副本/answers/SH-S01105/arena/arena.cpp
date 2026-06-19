#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;

constexpr int N = 1e5 + 7;

int n, m, k, a[N], b[N], c[N], xx[5], d[15][N];

void solve() {
	for (int i = 0; i < 4; ++i) scanf("%lld", x + i);
	for (int i = 1; i <= n; ++i) b[i] = a[i] ^ xx[i % 4];
	for (int i = n + 1; i <= k; ++i) b[i] = 0x3f3f3f;
	
	for (int i = 1; i <= k; ++i) {
		
	}
}

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);

	scanf("%lld %lld", &n, &m)
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	k = 0;
	while ((1 << k) < n) ++k;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= 1 << (k - i); ++j)
			scanf("%lld", &d[i][j]);
	}

	int T;
	scanf("%lld", &T);
	while (T--) solve();
	
	return 0;
}

