#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, n, a[200005], lsc[200005];
namespace H50 {
	int dp[2005][2005];
	void solve() {
		memset(dp, 0, sizeof dp);
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			dp[i][0] = dp[i - 1][0] + (a[i] == a[i - 1]) * a[i];
		}
		for(int i = 1; i <= n; ++i) {
			dp[0][i] = dp[0][i - 1] + (a[i] == a[i - 1]) * a[i];
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(j == i) continue;
				if(i > j) {
					if(j == i - 1) {
						for(int k = 0; k <= i - 2; ++k) {
							dp[i][j] = max(dp[i][j], dp[k][j] + (a[k] == a[i]) * a[i]);
						}
					}
					else {
						dp[i][j] = dp[i - 1][j] + (a[i] == a[i - 1]) * a[i];
					}
				}
				if(i < j) {
					if(i == j - 1) {
						for(int k = 0; k <= j - 2; ++k) {
							dp[i][j] = max(dp[i][j], dp[i][k] + (a[k] == a[j]) * a[j]);
						}
					}
					else {
						dp[i][j] = dp[i][j - 1] + (a[j] == a[j - 1]) * a[j];
					}
				}
				if(max(i, j) == n) {
					ans = max(ans, dp[i][j]); 
				}
			} 
		}
		cout << ans << endl;
		return;
	}
}
namespace H15 {
	int dp[200005][15], maxx[200005];
	void solve() {
		memset(dp, 0, sizeof dp);
		memset(maxx, 0, sizeof maxx);
		for(int i = 1; i <= 10; ++i) {
			dp[0][i] = -1e9;
		}
		maxx[0] = -1e9;
		for(int i = 1; i <= n; ++i) {
			for(int c = 1; c <= 10; ++c) {
				if(a[i - 1] == c) {
					dp[i][c] = max(dp[i - 1][c] + (a[i] == a[i - 1]) * a[i], max(maxx[i - 1], dp[i - 1][a[i]] + a[i]));
				}
				else {
					dp[i][c] = dp[i - 1][c] + (a[i] == a[i - 1]) * a[i];
				}
				maxx[i] = max(maxx[i], dp[i][c]);
			}
		}
		cout << maxx[n] << endl;
		return;
	}
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout); 
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		if(n <= 2000) {
			H50 :: solve();
		}
		else if(*max_element(a + 1, a + n + 1) <= 10) {
			H15 :: solve();
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
} 
// ORZ COMPOSITE_FUNCTION
// ORZ JXY2011
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ TIANTIAN2021

// everything i want to say is in T4 code
