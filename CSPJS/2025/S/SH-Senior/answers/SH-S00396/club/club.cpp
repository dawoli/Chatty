#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, c1, c2, c3, ans, a1[N], a2[N], a3[N], b1[N], b2[N], b3[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		c1 = c2 = c3 = ans = 0;
		scanf("%d", &n);
		int m = n / 2;
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a1[i] = x, a2[i] = y, a3[i] = z;
			int mx = max(max(a1[i], a2[i]), a3[i]);
			if (mx == a1[i]) b1[++c1] = i;
			else if (mx == a2[i]) b2[++c2] = i;
			else b3[++c3] = i;
			ans += mx;
		}
		if (c1 <= m && c2 <= m && c3 <= m) {
			printf("%d\n", ans);
			continue;
		}
		if (c2 > m) {
			swap(c1, c2);
			swap(a1, a2);
			swap(b1, b2);
		}
		if (c3 > m) {
			swap(c1, c3);
			swap(a1, a3);
			swap(b1, b3);
		}
		for (int i = 1; i <= c1; i++) {
			int j = b1[i];
			b1[i] = a1[j] - max(a2[j], a3[j]);
		}
		sort(b1 + 1, b1 + c1 + 1);
		for (int i = 1; i <= c1 - m; i++) ans -= b1[i];
		printf("%d\n", ans);
	}
	return 0;
}
