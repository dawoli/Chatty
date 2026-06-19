#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e3 + 10;

int n, m, k;
int x, y, d;
char mp[N][N];
bool vis[N][N];

pair <int, int> func(int X, int Y, int D) {
	if (D == 0) Y++;
	else if (D == 1) X++;
	else if (D == 2) Y--;
	else if (D == 3) X--;
	return {X, Y};
}

bool check(pair<int, int> D) {
	int X = D.first, Y = D.second;
	return X >= 1 && X <= n && Y >= 1 && Y <= m && mp[X][Y] == '.';
}

void solve() {
	memset(vis, false, sizeof vis);
	cin >> n >> m >> k >> x >> y >> d;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	while (k--) {
		vis[x][y] = true;
		pair <int, int> nx = func(x, y, d);
		if (check(nx)) x = nx.first, y = nx.second; 
		else d = (d + 1) % 4; 
	}
	vis[x][y] = true;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (vis[i][j]) ans++;
	cout << ans << "\n"; 
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
