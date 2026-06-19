#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, s[510], c[510];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		s[i] = ch - '0';
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(m == n) {
		int flag = 1;
		for(int i = 1; i <= n; i++)
			if(s[i] == 0 || c[i] == 0) {
				flag = 0; break;
			}
		if(flag == 0) cout << 0 << "\n";
		else {
			int ans = 1;
			for(int i = 1; i <= n; i++)
				ans = ans * i % mod;
			cout << ans << "\n";
		}
	}
	return 0;
}
