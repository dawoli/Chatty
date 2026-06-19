#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, ans, r;
char p[1005][1005];
bool b[1005][1005], s;
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i ++) {
		ans = 1;
		s = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		r = k;
		for (int j = 1; j <= n; j ++) {
			for (int f = 1; f <= m; f ++) {
				cin >> p[j][f];
			}
		}
		for (int j = 1; j <= n; j ++) {
			for (int f = 1; f <= m; f ++) {
				b[j][f] = 0;
			}
		}
		for (int j = x; j <= n;) {
			for (int f = y; f <= m;) {
				if (k == 0) break;
				if (d == 0) {
					if (f + 1 > m || p[j][f + 1] == 'x') {
						k --;
						d = (d + 1) % 4;
					}
					else {
						if (b[j][f + 1] == 0) ans ++;
						b[j][f + 1] = 1;
						k --;
						f ++;
					}
					if (k == 0) break;
					continue;
				}
				if (d == 1) {
					if (j + 1 > n || p[j + 1][f] == 'x') {
						k --;
						d = (d + 1) % 4;
					}
					else {
						if (b[j + 1][f] == 0) ans ++;
						b[j + 1][f] = 1;
						k --;
						j ++;
					}
					if (k == 0) break;
					continue;
				}
				if (d == 2) {
					if (f - 1 <= 0 || p[j][f - 1] == 'x') {
						k --;
						d = (d + 1) % 4;
					}
					else {
						if (b[j][f - 1] == 0) ans ++;
						b[j][f - 1] = 1;
						k --;
						f --;
					}
					if (k == 0) break;
					continue;
				}
				if (d == 3) {
					if (j - 1 <= 0 || p[j - 1][f] == 'x') {
						k --;
						d = (d + 1) % 4;
					}
					else {
						if (b[j - 1][f] == 0) ans ++;
						b[j - 1][f] = 1;
						k --;
						j --;
					}
					if (k == 0) break;
				}
			}
			break;
		}
		cout << ans;
	}
	return 0;
}
