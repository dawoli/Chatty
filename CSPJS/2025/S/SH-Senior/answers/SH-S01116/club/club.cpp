#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N][3], cnt[3], b[3][N];
void solve() {
	int ans = 0;
	cin >> n;
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) ans += a[i][0], b[0][++cnt[0]] = min(a[i][0] - a[i][1], a[i][0] - a[i][2]);
		else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) ans += a[i][1], b[1][++cnt[1]] = min(a[i][1] - a[i][0], a[i][1] - a[i][2]);
		else ans += a[i][2], b[2][++cnt[2]] = min(a[i][2] - a[i][0], a[i][2] - a[i][1]);
	}
	int t = -1;
	if (cnt[0] > n / 2) t = 0;
	else if (cnt[1] > n / 2) t = 1;
	else if (cnt[2] > n / 2) t = 2;
	if (t == -1) {
		cout << ans << '\n';
		return;
	}
	sort(b[t] + 1, b[t] + cnt[t] + 1);
	for (int i = 1; i <= cnt[t] - n / 2; i++) ans -= b[t][i];
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while (T--) solve();
}
