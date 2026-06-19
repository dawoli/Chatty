#include <iostream>
#include <cstring>
using namespace std;
int T, n, a[100001], ans, f[1001][1001];
void dfs(int lastr, int lastb, int points) {
	if (lastr == n || lastb == n) {
		ans = max(ans, points);
		return;
	}
	if (f[lastr][lastb] > points) return;
	f[lastr][lastb] = points;
	int i = max(lastr, lastb) + 1;
	if (a[lastr] == a[i]) dfs(i, lastb, points + a[i]);
	else dfs(i, lastb, points);
	if (a[lastb] == a[i]) dfs(lastr, i, points + a[i]);
	else dfs(lastr, i, points);
}
void solve() {
	ans = 0;
	memset(f, 0, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(0, 0, 0);
	cout << ans << endl; 
} 
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--) solve();
	return 0;
}
