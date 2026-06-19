#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000, MOD = 998244353;

ll n, m, ans, cnt[N];
string s;
ll a[N], c[N], rk[N];

ll A(ll n) {
	ll res = 1;
	for(int i = 1; i <= n; i ++) {
		res *= i;
		res %= MOD;
	}
	return res;
}

void bf() {
	do {
//		for(int i = 1; i <= n; i ++) 
//			cout << c[rk[i]] << ' ';
//		cout << '\n';
		ll fail = 0;
		for(int i = 1; i <= n; i ++) {
			if(fail >= c[rk[i]]) {
				fail ++;
			}
			else if(!a[i]) fail ++;
			if(n - fail < m) break;
		}
		//cout << fail << '\n';
		if(n - fail >= m) ans ++;
		ans %= MOD;
	}while(next_permutation(rk + 1, rk + 1 + n));
//	for(int i = 1; i <= n; i ++) {
//		ans *= A(cnt[i]);
//		ans %= MOD;
//	}
	cout << ans; 
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++) {
		a[i] = s[i - 1] - '0';
	}
	for(int i = 1; i <= n; i ++) {
		cin >> c[i];
		cnt[c[i]] ++;
		rk[i] = i;
	}
	
	if(n <= 18) bf();
	else {
		sort(c + 1, c + 1 + n);
		ll cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(c[i] == 0) cnt ++;
			else break;
		}
		if(n - cnt < m) cout << 0;
		else cout << A(n);
	}
	return 0;
}
