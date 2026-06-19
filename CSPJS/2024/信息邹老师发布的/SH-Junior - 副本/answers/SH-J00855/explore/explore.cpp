#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 10;

int T;
int n, m, k;
int sx, sy, sd;
char mp[N][N];
int vis[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct node {
	int x, y, d, step;
};

queue<node> que;

void bfs() {
	while (que.size()) {
		node hd = que.front();
		que.pop();
		if (hd.step == k) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					ans += vis[i][j];
				}
			}
			cout << ans;
			break;
		}
		int r = hd.x + dx[hd.d];
		int c = hd.y + dy[hd.d];
		if (r < 1 || r > n || c < 1 || c > m || mp[r][c] == 'x') {
			que.push({hd.x, hd.y, (hd.d + 1) % 4, hd.step + 1});
		}
		else {
			que.push({r, c, hd.d % 4, hd.step + 1});
			vis[r][c] = 1;
			//cout << r << ' ' << c << endl;
		}
	}
}

signed main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k;
		cin >> sx >> sy >> sd;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> mp[i][j];
			}
		}
		que.push({sx, sy, sd, 0});
		vis[sx][sy] = 1;
		bfs();
		cout << endl;
	}
}
