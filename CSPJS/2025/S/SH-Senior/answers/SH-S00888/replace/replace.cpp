#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, p[200010], h[200010][3];
string s[200010][3];
signed main() {
	cin >> n >> m;
	p[0] = 1;
	for(int i = 1; i <= 200000; i++)
		p[i] = p[i - 1] * 37 % mod;
	for(int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		for(int j = 0; j < s[i][1].size(); j++) h[i][1] = (h[i][1] + (s[i][1][j] - 'a' + 1) * p[j + 1] % mod) % mod;
		for(int j = 0; j < s[i][2].size(); j++) h[i][2] = (h[i][2] + (s[i][2][j] - 'a' + 1) * p[j + 1] % mod) % mod;
	}
	while(m--) {
		string t1, t2;
		cin >> t1 >> t2;
		int l1 = t1.size(), l2 = t2.size();
		if(l1 != l2) {
			cout << 0 << "\n";
			continue;
		}
		for(int i = 0; i < l1; i++) {
			
		}
	}
	return 0;
}
