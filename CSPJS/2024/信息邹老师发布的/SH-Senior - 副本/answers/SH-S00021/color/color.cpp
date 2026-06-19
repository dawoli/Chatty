/*
-- 50pts
dp[i][j]表示前i位，另一种颜色的最近编号为j的最大得分（i>j）
设 i 为红色，j 为蓝色
dp[i][j] -> 红 dp[i+1][j]
           -> 蓝 dp[i+1][i]

dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (a[i] == a[i+1]) * a[i+1]);
dp[i+1][i] = max(dp[i+1][i], dp[i][j] + (a[j] == a[i+1]) * a[i+1]);
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int T, n, dp[2][N], a[N]; 
signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);	
	cin >> T;
	while (T--) {
		scanf("%lld", &n);
		int mxx = 0, mx = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			mxx = max(mxx, a[i]);
			dp[0][i] = dp[1][i] = 0;
		}
		dp[0][0] = dp[1][0] = 0;
		if (n <= 2000) {
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[(i+1) & 1][j] = max(dp[(i+1) & 1][j], dp[i & 1][j] + (a[i] == a[i+1]) * a[i+1]);
				dp[(i+1) & 1][i] = max(dp[(i+1) & 1][i], dp[i & 1][j] + (a[j] == a[i+1]) * a[i+1]);
			}
		}
		for (int i = 0; i < n; ++i)
			mx = max(mx, dp[n & 1][i]);
	    } else {
            memset(dp, -0x3f, sizeof dp);
        
	    	for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= mxx; ++j) {
				if (dp[i & 1][j] >= 0) {
				dp[(i+1) & 1][j] = max(dp[(i+1) & 1][j], dp[i & 1][j] + (a[i] == a[i+1]) * a[i+1]);
				dp[(i+1) & 1][a[i]] = max(dp[(i+1) & 1][a[i]], dp[i & 1][j] + (j == a[i+1]) * a[i+1]);
			    } else {
			    	dp[(i+1) & 1][a[i]] = max(dp[(i+1) & 1][a[i]], 0ll);
				}
			}
		}
		for (int i = 1; i <= mxx; ++i)
		    mx = max(mx, dp[n & 1][i]);
		}
		
		printf("%lld\n", mx);
	}
} 
/*
1
4
1 2 3 4
*/
