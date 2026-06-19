#include <iostream>
const int N = 2e5 + 9;
int n, a[N];
void solve1() {
	int ans = 0;
	for (int i = 0; i < (1 << n) - 1; i++) {
		int cur = 0;
		for (int r = 0; r < n; r++) {
			for (int l = r - 1; l >= 0; l--) {
				int digl = (i >> (n - l)) & 1;
				int digr = (i >> (n - r)) & 1;
				if (digl == digr and a[l] == a[r]) {
					cur += a[r];
					break;
				}
			}
		}
		if (cur > ans) {
			ans = cur;
		}
	}
	printf("%d\n", ans);
}
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	if (n <= 15) solve1();
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}