#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int dx[5] = {0, 1, 0, -1};
const int dy[5] = {1, 0, -1, 0};
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m, k;
		cin >> n >> m >> k;
		int sx, sy, sd;
		cin >> sx >> sy >> sd;
		char arr[N][N];
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= m; j++) {
				arr[i][j] = str[j - 1];
			}
		}
		int x = sx, y = sy, d = sd;
		bool vis[N][N] = {false};
		vis[sx][sy] = true;
		while (k > 0) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m || arr[nx][ny] == 'x' ) {
				d = (d + 1) % 4;
			}
			else {
				x = nx;
				y = ny;
				vis[nx][ny] = true;
			}
			k--;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (vis[i][j]) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
