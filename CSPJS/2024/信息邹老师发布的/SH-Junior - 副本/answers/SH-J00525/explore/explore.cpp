# include <iostream>
using namespace std;
int n, m, k, xn, yn, d, ans = 1, mp[1001][1001];
int nx[8] = {1, 0, -1, 0, 1, 0, -1, 0}, ny[8] = {0, -1, 0, 1, 0, -1, 0, 1};
bool vis[1001][1001];
void dfs(int xx, int yy) {
	for (int i = d, x, y; i < 8; i++) {
		k--;
		if (k <= 0) return ;
		x = xx + nx[i], y = yy + ny[i];
		if (x >= 0 && x < n && y >= 0 && y < m 
		&& mp[x][y] == 0) {
			if (vis[x][y] == 0) ans++;
			vis[x][y] = 1;
			d = i;
			dfs(x, y);
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k >> xn >> yn >> d;
		char s;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> s;
				if (s == 'x') {
					mp[j][k] = 1;
				} else {
					mp[j][k] = 0;
				}
			}
		}
		vis[0][0] = 1;
		dfs(xn, yn);
		cout << ans << endl;
	}
	return 0;
}
