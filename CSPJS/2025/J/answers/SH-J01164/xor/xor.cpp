#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
#define M 500005
ll n, k, a[M], pre[M], dp[N][N], dp2[M], ans;
map<ll, ll> mp;
void solveDP(){
	for(ll i = 0; i <= n; i++) dp[i][0] = 1;
	mp[0] = 1;
	for(ll i = 1; i <= n; i++){
		pre[i] = pre[i - 1] ^ a[i];
		for(ll j = 1; j <= n; j++){
			dp[i][j] |= dp[i - 1][j];
			if(mp[pre[i] ^ k]){
				dp[i][j] |= dp[mp[pre[i] ^ k] - 1][j - 1];
			}
		}
		mp[pre[i]] = i + 1;
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= n; j++){
			if(dp[i][j]) ans = j;
		}
		cout << ans << " ";
	}
	cout << endl;
	cout << ans << endl;
}
void solveDP2(){
	dp2[0] = 0;
	mp[0] = 1;
	for(ll i = 1; i <= n; i++){
		dp2[i] = dp2[i - 1];
		pre[i] = pre[i - 1] ^ a[i];
		if(mp[pre[i] ^ k]) dp2[i] = max(dp2[i], mp[pre[i] ^ k]);
		mp[pre[i]] = max(mp[pre[i]], dp2[i] + 1);
	}
	for(ll i = 0; i <= n; i++) ans = max(ans, dp2[i]);
	cout << ans << endl;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	solveDP2();
	return 0;
}
