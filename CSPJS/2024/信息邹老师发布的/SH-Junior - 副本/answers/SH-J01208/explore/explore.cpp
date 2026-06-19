#include <bits/stdc++.h>
using namespace std;
int t; 
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char c[1010][1010];
int f[1010][1010];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(f, 0, sizeof(f));
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d; cin >> x >> y >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
			}
		}
		f[x][y] = 1;
		while (k--) {
			int dx = x + dir[d][0];
			int dy = y + dir[d][1];
			if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && c[dx][dy] == '.') {
				x = dx;
				y = dy; 
				f[x][y] = 1;
			} 
			else d = (d + 1) % 4;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (f[i][j] == 1) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
