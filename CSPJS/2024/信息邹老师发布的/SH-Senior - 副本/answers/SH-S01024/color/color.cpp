#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[200005], dp[2005][2005][2];
signed main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < i; j++){
				dp[i][j][0] = dp[i][j][1] = 0;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < i; j++){
				dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] + (a[i] == a[i-1] ? a[i] : 0));
				if (j == i - 1){
					for (int u = 0; u < i - 1; u++){
						dp[i][j][0] = max(dp[i][j][0], dp[i-1][u][1] + (a[i] == a[u] ? a[i] : 0));
					}
				}
			}
			for (int j = 0; j < i; j++){
				dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + (a[i] == a[i-1] ? a[i] : 0));
				if (j == i - 1){
					for (int u = 0; u < i - 1; u++){
						dp[i][j][1] = max(dp[i][j][1], dp[i-1][u][0] + (a[i] == a[u] ? a[i] : 0));
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
		}
		cout << ans << endl;
	}
	return 0;
} 
