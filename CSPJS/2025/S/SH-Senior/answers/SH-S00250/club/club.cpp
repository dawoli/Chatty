#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, a[maxn], b[maxn], c[maxn], dp[2][210][210], f[2][maxn];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> t;
	while (t--) {
		cin >> n;
		int state3 = 1, state2 = 1, state = 0;
		if (n <= 201) state = 1;
		int val = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0) state2 = 0;
			if (c[i] != 0) state3 = 0;
		}
		if (state == 1) {
			for (int i = 1; i <= n; i++, val = 1 - val) {
				for (int x = 0; x <= min(n / 2, i); x++) {
					for (int y = max(0, i - x - n/2); y <= min(n/2, i - x); y++) {
						if (x!=0) dp[1-val][x][y] = max(dp[val][x-1][y] + a[i], dp[1-val][x][y]);
						if (y!=0) dp[1-val][x][y] = max(dp[val][x][y-1] + b[i], dp[1-val][x][y]);
						if (i-x-y!=0) dp[1-val][x][y] = max(dp[val][x][y] + c[i], dp[1-val][x][y]);
					}
				}
			}
			int ans = 0;
			for (int x = 1; x <= n / 2; x++) {
				for (int y = max(0, n - x -n/2); y <= min(n/2, n - x); y++) {
					ans = max(ans, dp[0][x][y]);
				}
			}
			cout << ans << '\n';
		}
		else if (state2 == 1) {
			sort(a+1, a + n + 1);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i];
			}
			cout << ans << '\n';
		}
		else if (state3 == 1) {
			for (int i = 1; i <= n; i++, val = 1 - val) {
				for (int x = 0; x <= min(n / 2, i); x++) {
						if (x!=0) f[1-val][x] = max(f[val][x-1] + a[i], f[1-val][x]);
						if (i - x != 0) f[1-val][x] = max(f[val][x] + b[i], f[1-val][x]);
				}
			}
			int ans = 0;
			for (int x = 1; x <= n / 2; x++) {
					ans = max(ans, f[0][x]);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
