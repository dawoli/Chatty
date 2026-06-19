#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, c[N], ans;

signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		c[x]++;
		ans = max(ans, c[x]);
	}
	printf("%d", ans);
	return 0;
}
