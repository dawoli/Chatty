#include <bits/stdc++.h>
using namespace std;
const int N = 1515;
int t, n, m, k, ans;
int x, y, d;
int xd[] = {0, 1, 0, -1};
int yd[] = {1, 0, -1, 0};
char matrix[N][N];
bool vis[N][N];
void minit() {
	for(int i = 0;i <= n+1;i++) {
		matrix[i][0] = matrix[i][m+1] = 'x';
	}
	for(int i = 0;i <= m+1;i++) {
		matrix[0][i] = matrix[n+1][i] = 'x';
	}
}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int i = 1;i <= t;i++) {
		memset(vis, false, sizeof(vis));
		ans = 0;
		cin >> n >> m >> k;
		minit();
		cin >> x >> y >> d;
		for(int x = 1;x <= n;x++) {
			for(int y = 1;y <= m;y++) {
				cin >> matrix[x][y];
			}
		}
		for(int j = 1;j <= k;j++) {
			if(!vis[x][y]) {
				vis[x][y] = true;
				ans++;
			}
			int nx = x + xd[d];
			int ny = y + yd[d];
			if(matrix[nx][ny] == '.') {
				x = nx, y = ny;
			}
			else {
				d = (d+1) % 4;
			}
		}
		if(!vis[x][y]) {
			vis[x][y] = true;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
