#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	freopen("explore.in.txt", "r", stdin);
	freopen("explore.out.txt", "w", stdout);
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m, k, x, y, d, ans = 1;
		char map[1101][1101];
		bool flag[1101][1101];
		for (int i = 1; i <= 1101; i++)
			memset(flag, false, sizeof(flag));
		scanf ("%d%d%d", &n, &m, &k);
		scanf ("%d%d%d", &x, &y, &d);
		for (int i = 1; i <= n; i++)
			scanf ("%s", map[i] + 1);
		for (int i = 1; i <= k; i++) {
			int x_ = x, y_ = y;
			if (d == 0) y_--;
			if (d == 1) x_++;
			if (d == 2) y_++;
			if (d == 3) x_--;
			if ((x_ >= 1 && x_ <= m) && (y_ >= 1 && y_ <= n) && map[x_][y_] == '.') {
				if (flag[x_][y_] == false) ans++;
				x = x_, y = y_; flag[x][y] = true;
			}
			else d = (d + 1) % 4;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
