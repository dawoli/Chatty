#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int t, n, k , m, cnt, map[1005][1005], x0, y0, d, s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[1005][1005];
char c;
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c;
				if (c == '.') map[i][j] = 1;
				else map[i][j] = 0;
			}
		}
		vis[x0][y0] = 1;
        while (k) {
        	int nx = x0 + dx[d], ny = y0 + dy[d];
        	if (map[nx][ny] == 1) {
        		x0 = nx;
        		y0 = ny;
        		vis[nx][ny] = 1;
        		k--;
			}
			else {
				d = (d + 1) % 4;
				k--;
			}
		}
	    for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if(vis[i][j]) cnt++;
		cout << cnt << endl;
	}
	return 0;
} 
