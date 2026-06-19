// explore

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 10;
int gX[4] = {0, 1, 0, -1}, gY[4] = {1, 0, -1, 0}, n, m;
bool gVis[N][N];
string gS[N];

inline bool In(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && gS[x][y] == '.';
}

signed main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while (t--) {
		int k, x, y, d;
		cin >> n >> m >> k >> x >> y >> d;
		
		for (int i = 1; i <= n; i++)
			cin >> gS[i], gS[i] = " " + gS[i];
		
		gVis[x][y] = true;
		while (k--) {
			int tx = x + gX[d], ty = y + gY[d];
			if (In(tx, ty)) x = tx, y = ty, gVis[tx][ty] = true;
			else d = (d + 1) % 4;
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				ans += gVis[i][j];
		
		cout << ans << endl;
		memset(gVis, false, sizeof(gVis));
	}
	
	return 0;
}
