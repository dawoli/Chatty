#include<bits/stdc++.h>
#define int long long
using namespace std;
int TTT;
const int N = 1e6 + 10;
int a[N];
int dp[115][115][115];
int n;
signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> TTT;
	while(TTT--) {
		cin >> n;
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			maxx = max(maxx,a[i]);
		}
		for (int i = 0; i <= maxx + 5; i++) {
			for (int j = 0; j <= maxx + 5; j++) {
				for (int k = 0; k <= maxx + 5; k++) dp[i][j][k] = 0;
			}
		}
		for (int i = 3 ; i <= n; i++) {
			for (int j = 1;j < i; j++) {
				for (int k = 1; k < i; k++) {//Ã¶¾Ù 
					if(j == k) continue;
					if(j != i - 1 && k != i - 1) continue;
					if(a[i] == a[k]) dp[i][a[j]][a[i]] = max(dp[i - 1][a[j]][a[k]] + a[i] ,dp[i][a[j]][a[i]]);//i -> blue
					if(a[i] == a[j]) dp[i][a[i]][a[k]] = max(dp[i - 1][a[j]][a[k]] + a[i],dp[i][a[i]][a[k]]);
					dp[i][a[i]][a[k]] = max(dp[i][a[i]][a[k]],dp[i - 1][a[j]][a[k]]);
					dp[i][a[j]][a[i]] = max(dp[i][a[j]][a[i]],dp[i - 1][a[j]][a[k]]);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans = max(ans,dp[n][a[n]][a[i]]);
		}
		for (int i = 1; i < n; i++) {
			ans = max(ans,dp[n][a[i]][a[n]]);
		}
		cout << ans << endl;
		
	}
	return 0;
}
