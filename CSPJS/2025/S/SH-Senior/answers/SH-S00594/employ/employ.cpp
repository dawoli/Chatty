#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, N = 505;
int n, m, c[N], inv[N], fac[N], finv[N];
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	fac[0] = inv[0] = finv[0] = 1;
	for (int i = 1; i <= n; i++){
		fac[i] = fac[i - 1] * i % MOD;
		int k = MOD / i, r = MOD % i;
		inv[i] = (MOD - k) * inv[r] % MOD;
		finv[i] = finv[i - 1] * i % MOD;
	}
	s = ' ' + s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	bool flag = 1;
	for (int i = 1; i < s.size(); i++) 
		if (s[i] != '1')
			flag = 0;
	if (flag){
		cout << fac[n];
		return 0;
	}
	if (m == n) cout << 0;
	return 0;
} 
