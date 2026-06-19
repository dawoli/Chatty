#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
#define M 1005
ll dp[N][M][2];
ll T, n, m;
ll a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	n = m = 1000;
	for(ll i = 0; i <= n; i++){
		if(i * 2 > m) break;
		for(ll j = 0; j <= m; j++){
			dp[i][j][0] = dp[i][j][1] = INT_MAX;
			if(i == 0){
				if(j == 0) dp[i][j][0] = dp[i][j][1] = 0;
				continue;
			}
			for(ll k = 0; k <= 9; k++){
				if(j < a[k]) continue;
				if(k == 0){
					if(dp[i - 1][j - a[k]][0] >= 0 && dp[i - 1][j - a[k]][0] <= 9) dp[i][j][0] = min(dp[i][j][0], k);
				}else{
					if(dp[i - 1][j - a[k]][0] >= 0 && dp[i - 1][j - a[k]][0] <= 9) dp[i][j][0] = min(dp[i][j][0], k), dp[i][j][1] = min(dp[i][j][1], k);
				}
			}
		}
	}
	cin >> T;
	while(T--){
		cin >> m;
		n = m;
		bool falg = false;
		for(ll i = 1; i <= n; i++){
			if(i * 2 > m) break;
			if(dp[i][m][1] >= 0 && dp[i][m][1] <= 9){
				falg = true;
				printf("%d", dp[i][m][1]);
				ll tm = m;
				ll ti = i;
				ll uset = a[dp[ti][tm][1]];
				while(ti > 1){
					tm -= uset;
					ti--;
					printf("%d", dp[ti][tm][0]);
					uset = a[dp[ti][tm][0]];
				}
				printf("\n");
				break;
			}
		}
		if(!falg) printf("-1\n");
	}
	return 0;
}
