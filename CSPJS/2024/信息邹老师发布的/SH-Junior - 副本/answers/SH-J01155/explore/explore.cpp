#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int T, n, m, k;
char mp[N][N];
bool vis[N][N];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &k);
		int cur_x, cur_y, cur_d;
		scanf("%d %d %d", &cur_x, &cur_y, &cur_d);
		for (int i = 1; i <= n; i ++)
			scanf("%s", &mp[i][1]);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				vis[i][j] = false;
		for (int i = 1; i <= k; i ++) {
			vis[cur_x][cur_y] = true;
			int new_x, new_y;
			if (cur_d == 0) {
				new_x = cur_x;
				new_y = cur_y + 1;
			} else if (cur_d == 1) {
				new_x = cur_x + 1;
				new_y = cur_y;
			} else if (cur_d == 2) {
				new_x = cur_x;
				new_y = cur_y - 1;
			} else {
				new_x = cur_x - 1;
				new_y = cur_y;
			}
			if (new_x >= 1 && new_x <= n
			&& new_y >= 1 && new_y <= m
			&& mp[new_x][new_y] == '.') {
				cur_x = new_x;
				cur_y = new_y;
			} else {
				cur_d = (cur_d + 1) % 4;
			}
			vis[cur_x][cur_y] = true;
//			printf("%d %d %d\n", cur_x, cur_y, cur_d);
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (vis[i][j]) ans ++;
		printf("%d\n", ans);
//			for (int j = 1; j <= m; j ++)
//				scanf("%c", &mp[i][j]);
//		for (int i = 1; i <= n; i ++) {
//			for (int j = 1; j <= m; j ++) {
//				printf("%c ", mp[i][j]);
//			}
//			printf("\n");
//		}
//		printf("-----------\n");
	}
	return 0;
}
