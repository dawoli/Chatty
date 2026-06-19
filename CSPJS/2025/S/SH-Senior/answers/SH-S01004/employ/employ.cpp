#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
using u64 = unsigned long long;
const int mod = 998244353;
#define int long long
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> c(n + 1);
    for(int i = 0; i < n; i++){
    	cin >> c[i];
	}
    vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(1 << n , vector<int>(n + 1)));
	dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
//    	cout << i << ": " << endl;
    	for(int j = 0; j < (1 << n); j++){
//    		cout << j << ": ";
    		for(int k = 0; k <= n; k++){
	    		for(int l = 0; l < n; l++){
		    		if(j & (1 << l)){
		    			if(s[i] == '1'){
			    			if(k >= c[l]){
			    				dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-(1<<l)][k]) % mod;
							}
							if(k <= c[l] && k){
								dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-(1<<l)][k-1]) % mod;
							}
						}else{
							dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-(1<<l)][k]) % mod;
						}
					}
				}
//				cout << dp[i][j][k] << ' ';
			}
//			cout << endl;
		}
	}
	int ans = 0;
    for(int j = m; j <= n; j++){
    	ans = (ans + dp[n][(1 << n)-1][j]) % mod;
	}
//		cout << endl;
	cout << ans;
    fclose(stdin);
    fclose(stdout);
}
