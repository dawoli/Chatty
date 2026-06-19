#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e3 + 5;
const struct { int dx, dy; } d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int t, n, m;
char s[N][N];
int	dis[N][N], w[N][N], tot;
struct node { int x, y, px, py; };
queue<node> Q[N * N];
void clear(queue<node> &q) {
	while (!q.empty()) q.pop();
}
void bfs(int si, int sj) {
	memset(dis, -1, sizeof(dis));
	clear(Q[0]);
	Q[0].push({si, sj, 0, 0});
	for (int k = 0; k <= tot; k++) {
		clear(Q[k + 1]);
		while (!Q[k].empty()) {
			auto _ = Q[k].front();
			int x = _.x, y = _.y;
			dis[x][y] = dis[_.px][_.py] + 1;
			w[x][y] = k;
			if (x == n && y == m) return;
			Q[k].pop();
			for (auto _ : d) {
				int tx = x + _.dx, ty = y + _.dy;
				if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if (dis[tx][ty] != -1) continue;
				if (s[tx][ty] == '.') {
					Q[k].push({tx, ty, x, y});
					dis[tx][ty] = dis[x][y] + 1;
					w[tx][ty] = k;
				} else if (s[tx][ty] == '$') {
					Q[k + 1].push({tx, ty, x, y});
				}
			}
		}
	}
}
int main() {
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	for (cin >> t; t; t--) {
		cin >> n >> m;
		tot = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> s[i][j], tot += (s[i][j] == '$');
		bfs(1, 1);
		cout << w[n][m] << " " << dis[n][m] << '\n';
	}
	return 0;
}
