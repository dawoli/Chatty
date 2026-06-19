#include <bits/stdc++.h>

using namespace std;

char mp[1010][1010];
bool mark[1010][1010];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int sx, sy, sd;
		scanf("%d%d%d", &sx, &sy, &sd);
		
		for (int i = 1; i <= n; i++) {
			scanf("%s", mp[i] + 1);
		}
		
		int x = sx, y = sy, d = sd;
		int now = 0;
		while (now <= k) {
			mark[x][y] = true;
			
			int nx = -1, ny = -1;
			if (d == 0) {
				nx = x, ny = y + 1;
			} else if (d == 1) {
				nx = x + 1, ny = y;
			} else if (d == 2) {
				nx = x, ny = y - 1;
			} else if (d == 3) {
				nx = x - 1, ny = y;
			}
			
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.') {
				x = nx, y = ny;
			} else {
				d = (d + 1) % 4;
			}
			
			now++;
		}
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mark[i][j]) {
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				mark[i][j] = false;
			}
		}
	}
	return 0;
}

