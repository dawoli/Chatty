#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		int n, vis[2005] = {0}, dp[2005][2] = {0};
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			int a;
			scanf("%d", &a);
			int p = dp[vis[a]][0] + a;
			if (!vis[a]) dp[i][0] = dp[i - 1][0];
			else dp[i][0] = max(dp[i - 1][0], p);
			if (dp[i][0] == p && dp[i - 1][0] != p) dp[i][1] = dp[i - 1][1];
			else if (vis[a]) dp[i][1] = max(dp[i - 1][1], dp[vis[a]][1] + a);
			else dp[i][1] = dp[i - 1][1];
			vis[a] = i;
		}
		printf("%d\n", dp[n][0] + dp[n][1]);
	}
	return 0;
}
