#include<iostream>
#include<cstring>
using namespace std;
int t, n;
namespace sub1 {
	const int maxn = 105;
	int mv, ans;
	int a[maxn];
	int dp[maxn][maxn][maxn];
	void solve() {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
			mv = max(mv, a[i]);
		}
		memset(dp, 0xcf, sizeof(dp));
		dp[0][0][0] = 0;
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= mv; j ++) {
				for (int k = 0; k <= mv; k ++) {
					if (a[i] == j) {
						dp[i][a[i]][k] = max(dp[i][a[i]][k], dp[i - 1][j][k] + a[i]);
					}
					else {
						dp[i][a[i]][k] = max(dp[i][a[i]][k], dp[i - 1][j][k]);
					}
					if (a[i] == k) {
						dp[i][j][a[i]] = max(dp[i][j][a[i]], dp[i - 1][j][k] + a[i]);
					}
					else {
						dp[i][j][a[i]] = max(dp[i][j][a[i]], dp[i - 1][j][k]);
					}
				}
			}
		}
		for (int j = 0; j <= mv; j ++) {
			for (int k = 0; k <= mv; k ++) {
				ans = max(ans, dp[n][j][k]);
			}
		}
		printf("%d\n", ans);
	}
}
namespace sub2 {
	const int maxn = 2e5 + 5;
	const int maxv = 12;
	int mv, ans;
	int a[maxn];
	int dp[maxn][maxv][maxv];
	void solve() {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
			mv = max(mv, a[i]);
		}
		memset(dp, 0xcf, sizeof(dp));
		dp[0][0][0] = 0;
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= mv; j ++) {
				for (int k = 0; k <= mv; k ++) {
					if (a[i] == j) {
						dp[i][a[i]][k] = max(dp[i][a[i]][k], dp[i - 1][j][k] + a[i]);
					}
					else {
						dp[i][a[i]][k] = max(dp[i][a[i]][k], dp[i - 1][j][k]);
					}
					if (a[i] == k) {
						dp[i][j][a[i]] = max(dp[i][j][a[i]], dp[i - 1][j][k] + a[i]);
					}
					else {
						dp[i][j][a[i]] = max(dp[i][j][a[i]], dp[i - 1][j][k]);
					}
				}
			}
		}
		for (int j = 0; j <= mv; j ++) {
			for (int k = 0; k <= mv; k ++) {
				ans = max(ans, dp[n][j][k]);
			}
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n <= 100) {
			sub1::solve();
		}
		else {
			sub2::solve();
		}
	}
} 
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
*/
