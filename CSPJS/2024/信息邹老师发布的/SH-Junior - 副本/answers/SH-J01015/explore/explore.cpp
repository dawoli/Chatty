#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
int n, m, k;
int x, y, d;
char g[1005][1005];
bool vis[1005][1005][4];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
	cin >> n >> m >> k;
	cin >> x >> y >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
		}
	}

	memset(vis, false, sizeof(vis));
	vis[x][y][d] = true;
	while (k--) {
		int nx = x + dir[d][0],
			ny = y + dir[d][1],
			nd = d;
		if (vis[nx][ny][nd]) {
			break;
		}
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] == '.') {
			x = nx; y = ny; d = nd;
		}
		else {
			d = (d + 1) % 4;
		}
		vis[x][y][d] = true;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}