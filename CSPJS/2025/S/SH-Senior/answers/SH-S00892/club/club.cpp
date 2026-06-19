#include <bits/stdc++.h>
using namespace std;
const int _ = 1e5 + 10;
int t, n, m, a[_][3], b[_], c[3], cnt, d[_], ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		m = (n >> 1);
		c[0] = c[1] = c[2] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 2; j++) {
				cin >> a[i][j];
			}
			b[i] = 0;
			for (int j = 1; j <= 2; j++) {
				if (a[i][j] > a[i][b[i]]) b[i] = j;
			}
			ans += a[i][b[i]];
			c[b[i]]++;
		}
		int p = -1;
		if (c[0] > m) p = 0;
		if (c[1] > m) p = 1;
		if (c[2] > m) p = 2;
		if (p != -1) {
			cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (b[i] == p) {
					int r = a[i][p];
					if (p == 0) r -= max(a[i][1], a[i][2]);
					if (p == 1) r -= max(a[i][0], a[i][2]);
					if (p == 2) r -= max(a[i][0], a[i][1]);
					d[++cnt] = r;
				}
			}
			sort(d+1, d+cnt+1);
			for (int i = 1; i <= c[p] - m; i++) {
				ans -= d[i];
			}
		}
		cout << ans;
		if (t) cout << '\n';
	}
	cout << endl;
	return 0;
}
