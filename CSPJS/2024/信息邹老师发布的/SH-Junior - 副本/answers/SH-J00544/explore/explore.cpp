#include <bits/stdc++.h>
using namespace std;
const int N = 1001, D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k, x, y, d, mp[N][N], vst[N][N];
void init()
{
	for (int i = 0; i < N; ++i) {
		fill(mp[i], mp[i] + N, 0);
		fill(vst[i], vst[i] + N, 0);
	}
}
void solve()
{
	init();
	cin >> n >> m >> k >> x >> y >> d; cin.ignore();
	for (int i = 1; i <= n; ++i) {
		string s;
		getline(cin, s);
		for (int j = 1; j <= m; ++j)
			if (s[j - 1] == '.') mp[i][j] = 1;
	}
	vst[x][y] = 1;
	while (k--) {
		int nx = x + D[d][0], ny = y + D[d][1];
		if (0 < nx && 0 < ny && nx <= n && ny <= m && mp[nx][ny]) {
			x = nx;
			y = ny;
			vst[x][y] = 1;
		}
		else d = (d + 1) % 4;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			ans += vst[i][j];
	cout << ans << '\n';
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}


