#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
#define mod 998244353
ll n, a[N], pre[N][N], num[N][N], k[N], jc[N], invjc[N], ans, ttm;
ll pw(ll x, ll p){
	ll r = x, res = 1;
	while(p){
		if(p % 2){
			res = (res * r) % mod;
			p--;
		}
		else{
			r = (r * r) % mod;
			p /= 2;
		}
	}
	return res;
}
ll init(){
	jc[0] = 1;
	invjc[0] = 1;
	for(ll i = 1; i <= n; i++){
		jc[i] = (jc[i - 1] * i) % mod;
		invjc[i] = pw(jc[i], mod - 2);
	}
}
ll C(ll n, ll m){
	return (((jc[n] * invjc[n - m]) % mod) * invjc[m]) % mod;
}
void dfs(ll i, ll mx, ll sm, ll m){
	if(sm > mx * 2 && m > 2 && m != ttm){
		ans = (ans + 1) % mod;
		ttm = m;
	}
	if(i == n + 1){
		return ;
	}
	dfs(i + 1, mx, sm, m);
	ttm = 0;
	dfs(i + 1, max(mx, a[i]), sm + a[i], m + 1);
}
void solve(){
	sort(a+1, a+n+1);
	for(ll i = 1; i <= n; i++){
		pre[i][1] = a[i];
		for(ll j = 2; j <= i; j++){
			pre[i][j] = pre[i - 1][j - 1] + a[i];
		}
	}
	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j < i; j++){
			if(k[j] < j) k[j] = j;
			while(k[j] < i - 1 && pre[k[j]][j] <= a[i]) k[j]++;
			if(pre[k[j]][j] > a[i]) num[i][j] = i - (k[j] - j + 1);
		}
	}
	init();
	for(ll i = 3; i <= n; i++){
		for(ll j = 2; j < i; j++){
			if(num[i][j] >= j) ans = (ans + C(num[i][j], j)) % mod;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	if(n <= 27) dfs(1, 0, 0, 0);
	else solve();
	cout << ans << endl;
	return 0;
}
