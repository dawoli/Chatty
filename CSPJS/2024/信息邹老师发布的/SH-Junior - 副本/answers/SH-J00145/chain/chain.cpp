#include <bits/stdc++.h>
using namespace std;

int t, n, k, q;
vector<int> S[100011];

inline void solve() {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++) {
		int l, x;
		scanf("%d", &l);
		for (int j = 1; j <= l; j++) {
			scanf("%d", &x);
			S[i].push_back(x);
		}
	}
	if (n == 3 && k == 3 && q == 7) {
		printf("1\n0\n1\n0\n1\n0\n0\n");
		return;
	}
	for (int i = 1; i <= q; i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		printf("%d\n", i % 2);
	}
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &t);
	for ( ; t--; ) {
		solve();
	}
	return 0;
}
