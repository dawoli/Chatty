#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int T, n, m, k, x, y, d, vis[N][N], ans;
char ma[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--) {
		ans = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++) vis[i][j] = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) cin >> ma[i][j];
		for(int i = 1; i <= k; i++) {
			if(!vis[x][y]) ans++, vis[x][y] = 1;
			int nx = x + dx[d], ny = y + dy[d];
			if(nx < 1 || nx > n || ny < 1 || ny > m || ma[nx][ny] == 'x') d = (d + 1) % 4;
			else x = nx, y = ny;
		}
		if(!vis[x][y]) ans++;
		cout << ans << "\n";
	}
	return 0;
}
