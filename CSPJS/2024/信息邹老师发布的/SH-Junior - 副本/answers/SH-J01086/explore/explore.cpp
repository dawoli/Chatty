#include <bits/stdc++.h>
using namespace std;
const int dx [4] = {0, 1, 0, -1};
const int dy [4] = {1, 0, -1, 0};
int n, m, k;
bool a [1010] [1010], vis [1010] [1010];
bool check (int x, int y) {
	if (x < 1 || x > n) return false;
	else if (y < 1 || y > m) return false;
	else if (a [x] [y]) return false;
	else return true;
}
int main () {
	freopen ("explore.in", "r", stdin);
	freopen ("explore.out", "w", stdout);
	int T;
	cin >> T;
	while (T --) {
		memset (a, 0, sizeof (a));
		memset (vis, 0, sizeof (vis));
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i ++) 
			for (int j = 1; j <= m; j ++) {
				char c;
				cin >> c;
				if (c == 'x') a [i] [j] = true;
			} 
		while (k --) {
			vis [x] [y] = 1;
			int nx = x + dx [d], ny = y + dy [d];
			if (check (nx, ny)) x = nx, y = ny;
			else d = (d + 1) % 4; 
			vis [x] [y] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) 
			for (int j = 1; j <= m; j ++)
				ans += vis [i] [j];
		cout << ans << endl;
	}
}