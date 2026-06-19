#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, MOD = 998244353;
int n, m, ans = 1;
string s;
int c[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) ans = (ans * i) % MOD;
	cout << ans << endl; 
	return 0;
} 
