#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;
int T, n, m, d[N], cnt[4];
ll a[N][4];
struct Node {
	ll dt, typ, idx;
	bool operator < (const Node &rhs) const {
		return dt < rhs.dt;
	}
} op[2 * N];
bool used[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;
		ll ans = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			used[i] = 0;
			ll mx = max(max(a[i][1], a[i][2]), a[i][3]);
			for (int j = 1; j <= 3; j ++)
				if (a[i][j] == mx) {
					cnt[j] ++;
					d[i] = j;
					break;
				}
			ans += mx;
		}
		m = 0;
		int duo = 0;
		if (cnt[1] > n / 2) duo = 1;
		else if (cnt[2] > n / 2) duo = 2;
		else if (cnt[3] > n / 2) duo = 3;
		if (duo == 0) {
			cout << ans << "\n";
			continue;
		}
		for (int i = 1; i <= n; i ++) {
			if (d[i] == duo) {
				for (int j = 1; j <= 3; j ++) if (j != duo) {
					Node cur;
					cur.dt = a[i][duo] - a[i][j];
					cur.typ = j; cur.idx = i;
					op[++m] = cur;
				}
			}
		}
		sort(op + 1, op + m + 1);
		for (int i = 1, j = 1; i <= m && j <= cnt[duo] - (n / 2); i ++) {
			if (cnt[op[i].typ] + 1 <= n / 2 && !used[op[i].idx]) {
				ans -= op[i].dt;
				cnt[op[i].typ] ++;
				used[op[i].idx] = 1;
				j ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
