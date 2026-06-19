#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 25000010
#define mod 998244353
int n, a[N], sum, dp[N], ans;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		sum += a[i];
		for(int j = sum; j >= a[i]; j--)
			dp[j] = (dp[j - a[i]] + dp[j]) % mod;
		for(int j = a[i + 1] + 1; j <= sum; j++)
			ans = (ans + dp[j]) % mod;
	}
	cout << ans << endl;
	return 0;
} 
