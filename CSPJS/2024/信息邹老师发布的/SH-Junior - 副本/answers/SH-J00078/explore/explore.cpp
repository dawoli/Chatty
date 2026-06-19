#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int N = 1010;

int t;
int dx[N] = {0, 1, 0, -1}, dy[N] = {1, 0, -1, 0};

signed main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n, m, k, x, y, d, ans = 1;
		map<pair<int, int>, bool> st;
		char c[N][N];
		cin >> n >> m >> k >> x >> y >> d;
		st[{x, y}] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
			} 
		}
		while (k--) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && c[nx][ny] == '.') {
				if (!st[{nx, ny}]) ans++;
				st[{nx, ny}] = 1;
				x = nx;
				y = ny;
			} else d = (d + 1) % 4;
		}
		cout << ans << endl;
	}
	return 0;
} 
