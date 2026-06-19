#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
int t, n, a[maxn*2], b[maxn*2], c[maxn*2], dp[2][maxn][maxn];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> t;
	while (t--) {
		cin >> n;
		int val = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		for (int i = 1; i <= n; i++, val = 1 - val) {
			for (int x = 1; x <= n / 2; x++) {
				for (int y = max(1, i - x - n/2); y <= i - x; y++) {
					dp[1-val][x][y] = max(dp[val][x][y] + c[i],
									max(dp[val][x][y-1] + b[i], 
									dp[val][x-1][y] + a[i]));
				}
			}
		}
		int ans = 0;
		for (int x = 1; x <= n / 2; x++) {
			for (int y = max(1, n - x -n/2); y <= n / 2; y++) {
				ans = max(ans, dp[0][x][y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
