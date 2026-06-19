#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int MR = (1 << 18) + 10;
const int MOD = 998244353;
int n, m, ans, c[N], dp[MR][N];
string s;

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s, s = " " + s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n) - 1; i++){
		int p = __builtin_popcount(i);
		for (int k = 1; k <= n; k++){
			if (i >> (k - 1) & 1){
				continue;
			}
			for (int j = 0; j <= p; j++){
				if (! dp[i][j]){
					continue;
				}
				bool flag = (s[p + 1] == '0') || (j >= c[k]);
				if (flag){
					(dp[i | (1 << k - 1)][j + 1] += dp[i][j]) %= MOD;
				}else{
					(dp[i | (1 << k - 1)][j] += dp[i][j]) %= MOD;
				}
			}
		}
	}
	for (int j = 0; j <= n - m; j++){
		(ans += dp[(1 << n) - 1][j]) %= MOD;
	}
	cout << ans << endl;
	return 0;
}
