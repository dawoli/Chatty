#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool a[N][N];
char s[N];
set<pair<int, int>> pos;

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		pos.clear();
		int n, m, k, x, y, d;
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		pos.insert(make_pair(x, y));
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s);
			for (int j = 0; j < (int) strlen(s); ++j) {
				if (s[j] == '.') a[i][j + 1] = 0;
				else a[i][j + 1] = 1;
			}
		}
		while (k--) {
			int nx, ny;
			if (d == 0) nx = x, ny = y + 1;
			else if (d == 1) nx = x + 1, ny = y;
			else if (d == 2) nx = x, ny = y - 1;
			else if (d == 3) nx = x - 1, ny = y;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !a[nx][ny]) {
				x = nx, y = ny;
			} else {
				d = (d + 1) % 4;
			}
			pos.insert(make_pair(x, y));
		}
		printf("%d\n", pos.size());
	}
	return 0;
}
