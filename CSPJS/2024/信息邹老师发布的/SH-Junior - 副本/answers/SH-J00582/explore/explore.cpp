#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int t, n, m, d;
bool mp[N][N], vis[N][N];

int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};

bool check(int nx, int ny) {
	if (nx == 0 || ny == 0 || nx > n || ny > m || mp[nx][ny]) return false;
	else return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> t;
	while (t --) {
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> d;
		int x, y, nd, ans = 1;
		cin >> x >> y >> nd;
		vis[x][y] = 1;
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				char ch; cin >> ch;
				if (ch == 'x') mp[i][j] = 1;
			}
		}
//		for (int i = 1; i <= n; ++ i) {
//			for (int j = 1; j <= m; ++ j)
//				cout << mp[i][j] << " ";
//			cout << endl; 
//		}
//		打印地图  地图读入没有问题
		while (d --) {
			if (check(x + dx[nd], y + dy[nd])) {
				x += dx[nd];
				y += dy[nd];
			}
			else nd = (nd + 1) % 4;
			if (!vis[x][y]) {
				vis[x][y] = 1;
				ans ++;
			}
			//cout << x << " " << y << " " << nd << endl;;
		}
		
		cout << ans << endl;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
