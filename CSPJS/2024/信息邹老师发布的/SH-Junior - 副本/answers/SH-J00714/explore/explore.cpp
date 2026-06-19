#include<iostream>
using namespace std;

int run[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool map[1005][1005], flag[1005][1005];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m, k, x, y, d, ans = 1;
		char c;
		cin >> n >> m >> k >> x >> y >> d;
		for (int j = 1; j <= n; j++) {
			for (int kk = 1; kk <= m; kk++) {
				cin >> c;
				flag[j][kk] = 0;
				if (c == '.') {
					map[j][kk] = 1;
				} else {
					map[j][kk] = 0;
				}
			}
		}
		flag[x][y] = 1;
		int dd;
		bool flag1 = 0;
		for (int j = 0; j < k; j++) {
			int xx = x + run[d][0], yy = y + run[d][1];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && map[xx][yy]) {
				x = xx;
				y = yy;
				if (!flag[x][y]) {
					ans++;
				}
				flag[x][y] = 1;
			} else {
				d = (d + 1) % 4;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
