#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

int T;
char a[1003][1003];
bool vis[1003][1003];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n, m, k, x, y, d;
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x, &y, &d);
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) 
				cin >> a[i][j];
		}
		int ans = 1;
		vis[x][y] = 1;
		for (int i = 1; i <= k; i++) {
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
				x = nx, y = ny;
				if (!vis[nx][ny]) 
					ans++;
				vis[nx][ny] = 1;
			}
			else {
				d = (d + 1) % 4;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
