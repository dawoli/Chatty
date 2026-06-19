#include <bits/stdc++.h>
using namespace std;
int n, m, bomb = 1e9, ans = 1e9;
string s[1005];
bool vis[1005][1005];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int b, int step) {
	if (s[x][y] == '$') b++;
	if (b > bomb) return ;
	if (x == n && y == m) {
		if (b < bomb) ans = step, bomb = b;
		else if (b == bomb) ans = min(ans, step);
		return ;
	}
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx > 0 && tx <= n && ty > 0 && ty <= m && !vis[tx][ty] && s[tx][ty] != '*') {
			dfs(tx, ty, b, step + 1); 
		}
	}
}
int main() {
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> s[i], s[i] = " " + s[i];
		bomb = ans = 1e9;
		memset(vis, 0, sizeof(vis));
		dfs(1, 1, 0, 0);
		cout << bomb << " " << ans << endl;
	}
	return 0;
}
