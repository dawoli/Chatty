#include <iostream>
#include <cstring>
using namespace std;
int T, n, m, k, x, y, d, sum;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool a[1001][1001], f[1001][1001];
char c[1001][1001];
void solve() {
	memset(a, 0, sizeof(a));
	memset(f, 0, sizeof(f));
	cin >> n >> m >> k >> x >> y >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'x') a[i][j] = 1; 
		}
	}
	sum = 1, f[x][y] = 1;
	while (k--) {
		int tx = x + dx[d], ty = y + dy[d];
		if (tx > 0 && tx <= n && ty > 0 && ty <= m && !a[tx][ty]) x = tx, y = ty;
		else d = (d + 1) % 4;
		if (!f[x][y]) sum++, f[x][y] = 1;
	}
	cout << sum << endl;
}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while (T--) solve();
	return 0;
}

