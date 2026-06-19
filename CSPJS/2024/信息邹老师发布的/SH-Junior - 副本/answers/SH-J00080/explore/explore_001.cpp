#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int T, n, m, k, nowX, nowY, nowD;
char c[N][N];
bool vis[N][N];

signed main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		cin >> nowX >> nowY >> nowD;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> c[i][j], vis[i][j] = false;
		vis[nowX][nowY] = true;
		while (k--) {
			int toX = nowX + dx[nowD];
			int toY = nowY + dy[nowD];
			if (toX >= 1 && toX <= n && toY >= 1 && toY <= m && c[toX][toY] != 'x')
				nowX = toX, nowY = toY;
			else nowD = (nowD + 1) % 4;
			vis[nowX][nowY] = true;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (vis[i][j]) ++cnt;
		cout << cnt << endl;
	}
	return 0;
}
