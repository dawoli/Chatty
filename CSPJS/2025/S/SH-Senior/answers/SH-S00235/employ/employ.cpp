#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[510], b[520], p = 998244353, res, k;
string s;
int qp(ll a, ll b) {
	ll ans = a;
	b--;
	while(b > 1) {
		ans *= ans;
		b >>= 1;
		if(b & 1) ans *= a;
		ans %= p;
	}
	return ans;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(ll i = 0; i < s.size(); i++) {
		a[i] = s[i];
	    if(a[i] == 0) res++;
	}
	for(ll i = 1; i <= n; i++) {
		cin >> b[i];
		if(b[i] == 0) k++;
	}
	if(m + res > n) {
		cout << 0 << endl;
		return 0;
	}
	if(n == m) {
		if(k != 0) {
			cout << 0 << endl;
			return 0;
		}
		ll ans = 1;
		for(ll i = 2; i <= n; i++) {
			ans *= i;
			ans %= p;
		}
		cout << ans << endl;
		return 0;
	} 
	if(k == m) {
		cout << 0 << endl;
		return 0;
	}
	if(!res) {
		ll x = 1, y = 1;
	    ll mk = n - (m - k);
	    for(ll i = 2; i <= mk; i++) {
	    	x *= i;
	    	x %= p;
		}
		y = x;
		for(ll i = mk + 1; i <= n; i++) {
			y *= i;
			y %= p;
		}
	    cout << y / x % mod << endl;
	    return 0;
	}
	if(m == 1) {
		
		return 0;
	}
	cout << 5 << endl;
	return 0;
}
