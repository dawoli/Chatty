#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
//int dp[510][5010];
int dp[25000010];
int s[5010];
const int p = 998244353;
signed main() {
//	system("fc polygon.out polygon.ans");
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	int ans = 0;
//	dp[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = s[i]; j >= 0; j--) {
//			dp[i][j] = dp[i - 1][j];
//			if (j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];
//			dp[i][j] %= p;
//			if (i >= 3 && j >= a[i] + 1 && j <= s[i - 1]) {
//				ans += dp[i - 1][j];
//				ans %= p;
//			}
//		}
//	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = s[i]; j >= a[i]; j--) {
			if (i >= 3 && j >= a[i] + 1 && j <= s[i - 1]) {
				ans += dp[j];
				ans %= p;
			}
			dp[j] += dp[j - a[i]];
			dp[j] %= p;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= 20; j++) {
//			cout << i << " " << j << " " << dp[i][j] << endl;
//		}
//	}
//	int ans = 0;
//	for (int i = 3; i <= n; i++) {
//		for (int j = a[i] + 1; j <= s[i - 1]; j++) {
//			ans += dp[i - 1][j];
//			ans %= p;
//		}
//	}
	printf("%d", ans % p);
	return 0;
}
