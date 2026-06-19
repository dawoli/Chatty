#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int t, n, m, k, x, y, d;
char g[N][N];
bool vis[N][N];
bool exist(int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m >> k >> x >> y >> d;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++) {
				cin >> g[j][k];
				vis[j][k] = 0;
			}
		int ans = 1;
		while (k > 0) {
			vis[x][y] = 1;
			int nx = x + dx[d], ny = y + dy[d];
			while (!exist(nx, ny) || g[nx][ny] == 'x')
				d = (d + 1) % 4, nx = x + dx[d], ny = y + dy[d], k--;
			x = nx, y = ny;
			if (!vis[x][y] && k > 0) ans++;
			k--;
		}
		cout << ans << endl;
	}
	return 0;
}
