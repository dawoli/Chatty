#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char a[1010][1010];
bool vis[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Node {int d, x, y, st;};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);

	int t, n, m, k, x0, y0, d0;
	long long cnt = 0;

	cin >> t;

	while (t--) {
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cin >> a[i][j];
		}

		vis[x0][y0] = 1;
		queue<Node> q;
		q.push((Node){d0, x0, y0, 0});
		while (!q.empty()) {
			Node f = q.front();
			q.pop();
			if (f.st >= k) { // 终止条件
				break;
			}
			int nx = f.x + dx[f.d], ny = f.y + dy[f.d];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == '.') {
				vis[nx][ny] = 1;
				q.push((Node){f.d, nx, ny, f.st + 1});
			} else {
				// cout << "--------------\n";
				q.push((Node){(f.d + 1) % 4, f.x, f.y, f.st + 1});
			}

		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				// cout << vis[i][j] << " ";
				if (vis[i][j]) cnt++;
			}
			// cout << "\n";
		}
		cout << cnt << "\n";
	}


	return 0;
}
