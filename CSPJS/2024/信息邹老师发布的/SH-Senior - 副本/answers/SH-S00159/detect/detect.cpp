#include <iostream>
#include <set>
using namespace std;
int T, n, m, L, vmax, d[100001], v0[100001], a[100001], p[100001], ans;
bool lo1, lo2;
void solve() {
	lo1 = 0, lo2 = 0, ans = 0;
	cin >> n >> m >> L >> vmax;
	for (int i = 1; i <= n; i++) cin >> d[i] >> v0[i] >> a[i];
	for (int i = 1; i <= m; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) lo1 &= (a[i] > 0);
	for (int i = 1; i <= n; i++) lo2 &= (a[i] == 0);
	//for (int i = 1; i <= n; i++) lo3 &= (a[i] < 0)
	if (lo1) {
		for (int i = 1; i <= n; i++) {
			int sup = (vmax * vmax - v0[i] * v0[i]) + d[i] * (a[i] * 2), sdown = a[i] * 2;
			if (sup <= p[m] * sdown) ans++;
		}
		cout << ans << " " << 1 << endl;
		return;
	}
	else if (lo2) {
		for (int i = 1; i <= n; i++) if (v0[i] > vmax && d[i] <= p[m]) ans++;
		cout << ans << " " << 1 << endl;
		return;
	}
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T--) solve();
	return 0;
}
