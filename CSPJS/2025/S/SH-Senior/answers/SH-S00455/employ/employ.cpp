#include <bits/stdc++.h>
#define il inline
#define N 510
#define mod 998244353
using namespace std;
typedef long long ll;

il ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch != '-' && !(ch >= '0' && ch <= '9')) ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
	return x * f;
}
ll n, m, cT, c[N], f[N];
string s;
void solveA() {
	cT = 0;
	for (int i = 1; i <= n; ++i) cT += (c[i] == 0);
	ll Ans = 1;
	for (int i = 1; i <= n - cT; ++i)
		(Ans *= i) %= mod;
	if (n - cT < m) cout << 0;
	else cout << Ans; 
}
void solvemn() {
	for (int i = 0; i < s.size(); ++i) cT += (s[i] == '1');
	if (cT != s.size()) cout << 0;
	else {
		cT = 0;
		for (int i = 1; i <= n; ++i) cT += (c[i] == 0);
		if(cT >= 1) cout << 0;
		else {
			ll Ans = 1;
			for (int i = 1; i <= n - cT; ++i)
				(Ans *= i) %= mod;
			cout << Ans;
		}
		
	}
}
void solveBF() {
	ll Ans = 0;
	for (int i = 1; i <= n; ++i) f[i] = i;
	do {
		ll los = 0; bool ok = true;
		for (int i = 1; i <= n; ++i)	
			if (los >= c[f[i]] || s[i - 1] == '0') ++los;
		Ans += (n - los >= m);
	} while(next_permutation(f + 1, f + n + 1));
	cout << Ans % mod;
}
int main() {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	n = read(); m = read(); cin >> s;
	for (int i = 1; i <= n ; ++i) c[i] = read();
	for (int i = 0; i < s.size(); ++i) cT += (s[i] == '1');
	if (n <= 10) solveBF();
	else if (cT == s.size()) solveA();
	else if (m == n) solvemn();
	return 0;
}

