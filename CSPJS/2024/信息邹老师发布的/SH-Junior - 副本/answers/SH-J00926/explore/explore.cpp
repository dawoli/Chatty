# include <bits/stdc++.h>
# include <iostream>

int t, n, m, k, x, y, d, cnt;
int nx, ny;
int movex[] = {0, 1, 0, -1};
int movey[] = {1, 0, -1, 0};
char pos;
int ans[10];
bool map[1005][1005];	// true: .     false: x
bool stepped[1005][1005];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) {
		memset(stepped, false, sizeof(stepped));
		scanf("%d%d%d\n", &n, &m, &k);
		scanf("%d%d%d\n", &x, &y, &d);
		for (int j = 1; j <= n; j++) {
			for (int h = 1; h <= m; h++) {
				scanf("%c", &pos);
				map[j][h] = (pos == '.');
			}
			scanf("\n");
		}
		stepped[x][y] = true;
		cnt = 1;
		for (int j = 0; j < k; j++) {
			nx = x + movex[d];
			ny = y + movey[d];
			if ((nx >= 1) && (nx <= n) && (ny >= 1) && (ny <= m) && (map[nx][ny])) {
				x = nx;
				y = ny;
				if (!stepped[x][y])  {
					stepped[x][y] = true;
					cnt++;
				}
			} else {
				d++;
				if (d == 4) {
					d = 0;
				}
			}
		}
		ans[i] = cnt;
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
} 
