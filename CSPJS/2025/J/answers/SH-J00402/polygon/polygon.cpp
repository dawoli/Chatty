#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5009, MOD = 998244353;
ll dp[N][N], a[N], n;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j <= 5001; j++) {
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (j + a[i] <= 5000) dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % MOD;
			else dp[i][5001] = (dp[i][5001] + dp[i - 1][j]) % MOD;
		}
	ll ans = 0;
	for (ll i = 3; i <= n; i++)
		for (ll j = a[i] + 1; j <= 5001; j++) ans = (ans + dp[i - 1][j]) % MOD;
	cout << ans;
	return 0;
}
