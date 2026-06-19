#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char s[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;

bool ok(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != 'x';
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		scanf("%d%d%d", &n, &m, &k);
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%s", s[i] + 1);
		}
		s[x][y] = '#';
		for (int i = 1; i <= k; i++) {
//			cout << "step " << i << ":" << endl;
			int newx = x + dx[d], newy = y + dy[d];
			if (ok(newx, newy)) {
//				cout << "debug: step + 1" << endl;
				x = newx;
				y = newy;
//				cout << "goto x:" << x << " y:" << y << endl;
			}
			else {
//				cout << "debug: turn" << endl;
				d = (d + 1) % 4;
//				cout << "turn, d = " << d << endl;
			}
			s[x][y] = '#';
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
//				printf("%c", s[i][j]);
				if (s[i][j] == '#') ret++;
			}
//			printf("\n");
		}
		printf("%d\n", ret);
	}
	return 0;
}
