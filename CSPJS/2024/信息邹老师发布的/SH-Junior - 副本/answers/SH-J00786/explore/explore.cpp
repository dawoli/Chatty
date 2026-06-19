#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int  n, m, d, x, y, k, t;
bool vis[1005][1005];
int dx[4] = {0, 1, 0, -1}, 
	dy[4] = {1, 0, -1, 0}; 

bool check(int x, int y) {
	return (x > 0 && x <= n) && (y > 0 && y <= m);
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k >> x >> y >> d;
		int ans = 1;
//		getchar();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> grid[i][j];
			}
		}
//		cout << "endofinput";
		for (int i = 1; i <= k; i++) {
//			cout << 'e';
			if (!check(x+dx[d], y+dy[d])) {
				d = (d+1) % 4;
//				cout << 'b';
				continue;
			}
			if (grid[x+dx[d]][y+dy[d]] == 'x') {
				d = (d+1) % 4;
				
				continue;
			}
//			cout << 'a';
			x += dx[d];
			y += dy[d];
//			cout << x << " " << y << " " << i << endl;
			if (!vis[x][y]){
				ans++;
				vis[x][y] = 1;
			}
		}
		cout << ans << endl;
//		cout << vis[1][1] << vis[1][2] << vis[1][3] << vis[1][4];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
