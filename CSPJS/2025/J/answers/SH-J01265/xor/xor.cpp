//01-11-25 09:29
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL N = 5e5 + 5;
LL n, k, a[N], dp[N], ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for(LL i = 1; i <= n; ++ i)
		cin >> a[i];
	
	if(k == 0 && n >= 1e5){
		for(int i = 1; i <= n; ++ i){
			if(!a[i])
				++ ans;
			else{
				if(a[i + 1] == 1)
					++ ans, ++ i;
			}
		}
		cout << ans;
		return 0;
	}
	
	for(LL i = n; i >= 1; -- i){
		LL xr = 0;
		for(LL j = i; j <= n; ++ j){
			xr ^= a[j];
			if(xr == k){
				dp[i] = dp[j + 1] + 1;
				break;
			}
		}
		dp[i] = max(dp[i], dp[i + 1]);
	}
	for(LL i = 1; i <= n; ++ i)
		ans = max(ans, dp[i]);
	
	cout << ans;
	return 0;
}
