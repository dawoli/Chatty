#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 5007, maxW = 5007, MOD = 998244353;

int n, W, a[maxN];
int dp[maxW];
/* 
dp[i][w] 表示前i个中，长度为w的总方案数 
故前i个中，选第i个，长度为w的方案数为dp[i-1][w-a[i]] 
*/

int qpow(int n, int m) {
	if(m == 0) return 1;
	int tmp = qpow(n, m / 2);
	if((m & 1) == 1) return tmp * tmp % MOD * n % MOD;
	else return tmp * tmp % MOD;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); 
	cin >> n;
	W = 5002;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	dp[0] = 1;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int ans_i = 0;
		for(int w=0; w<=a[i]; w++) 
			ans_i += dp[w], ans %= MOD;
		ans_i = ((qpow(2, i-1) - ans_i) % MOD + MOD) % MOD;
//		cout << i << ' ' << ans_i << endl;
		ans += ans_i;
		ans %= MOD;
		for(int w=W; w>=0; w--) {
			if(w >= a[i]) dp[w] = dp[w] + dp[w - a[i]];
			else dp[w] = dp[w];
			dp[w] %= MOD;
//			if(dp[w] != 0) cout << i << ' ' << w << ' ' << dp[w] << endl;
		}
	}
	cout << ans;
	return 0;
}


 
