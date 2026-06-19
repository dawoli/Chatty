#include <iostream> 
using namespace std;

int t, n, a[200005];
int dp[2005][2005][2][2];

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--) { 
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[0][0][0][0] = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				dp[1][0][i][j] = 0;
				dp[1][1][i][j] = 0;
			}
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (j <  i-1) dp[i][j][0][1] = max(dp[i-1][j][0][1], dp[i-1][j][0][0]);
				else dp[i][j][0][1] = dp[i][j][0][0];
				if (j <  i-1) dp[i][j][1][0] = max(dp[i-1][j][1][0], dp[i-1][j][1][1]);
				else dp[i][j][1][0] = dp[i][j][1][0];
				if (j <  i-1) dp[i][j][0][0] = max(dp[i-1][j][1][0], dp[i-1][j][0][0]) + (a[i] == a[j] ? a[i] : 0);
				else dp[i][j][0][0] = dp[i][j][0][0];
				if (j <  i-1) dp[i][j][1][1] = max(dp[i-1][j][1][0], dp[i-1][j][1][1]) + (a[i] == a[j] ? a[i] : 0);
				else dp[i][j][1][1] = dp[i][j][1][1];
			}
		}
		int ans = 0x80808080;
		for (int j = 1; j < n; j++) {
			ans = max(dp[n][j][0][1], ans);
			ans = max(dp[n][j][0][0], ans);
			ans = max(dp[n][j][1][0], ans);
			ans = max(dp[n][j][1][1], ans);
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
