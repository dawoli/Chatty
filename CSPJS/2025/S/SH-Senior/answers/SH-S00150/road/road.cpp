#include <bits/stdc++.h>

using namespace std;

const int N = 511, p = 998244353, M = 18;
int n, m, k, x;
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ans += 0LL + w;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &x);
		for (int j = 1; j <= n; j++)
			scanf("%d", &x);
	}
	printf("%lld\n", ans);
	return 0;
}
