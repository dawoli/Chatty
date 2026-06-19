#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, m, ans, a[N][3], b[N], c[N], d[N], cnt[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	int t;
	cin >> t;
	while (t--) {
		cnt[0] = cnt[1] = cnt[2] = m = ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
				++cnt[0], b[i] = 0;
				c[i] = max(a[i][1], a[i][2]);
			}
			else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
				++cnt[1], b[i] = 1;
				c[i] = max(a[i][0], a[i][2]);
			}
			else {
				++cnt[2], b[i] = 2;
				c[i] = max(a[i][0], a[i][1]);
			}
			ans += a[i][b[i]];
		}
		if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
			cout << ans << "\n";
			continue;
		}
		int x = 0;
		if (cnt[1] > n / 2) x = 1;
		if (cnt[2] > n / 2) x = 2;
		for (int i = 1; i <= n; ++i)
			if (b[i] == x) d[++m] = a[i][b[i]] - c[i];
		sort(d + 1, d + m + 1);
		for (int i = 1; i <= cnt[x] - n / 2; ++i)
			ans -= d[i];
		cout << ans << "\n";
	}
	return 0;
} 
