#include <bits/stdc++.h>

using namespace std;

const int N = (int)5e3 + 5, p = 998244353, Sum = 10001;
int n, a[N], dp[N][N << 1], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= Sum; j++) {
			dp[i][j] += dp[i - 1][j], dp[i][j] %= p;
			if (j >= a[i]) {
				dp[i][j] += dp[i - 1][j - a[i]], dp[i][j] %= p;
				if (j > (a[i] << 1))
					ans += dp[i - 1][j - a[i]], ans %= p;
			}
		}
		for (int j = Sum - a[i] + 1; j <= Sum; j++) {
			dp[i][Sum] += dp[i - 1][j], dp[i][Sum] %= p;
			ans += dp[i - 1][j], ans %= p;
		}
	}
	printf("%d\n", ans);
	return 0;
}
