#include <bits/stdc++.h>
using namespace std;
int n, m, c[505], sz, cz;
string s;
const long long mod = 998244353;
long long ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < s.length(); ++i) 
		if (s[i] == '0') sz++;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i] == 0) cz++;
	}
	sort(c + 1, c + n + 1);
	if (n == m) {
		if (sz || cz) {
			cout << 0 << "\n";
			return 0;
		}
		for (int i = 1; i <= n; ++i) ans = ans * i % mod;
		cout << ans << "\n";
	} else if (sz == 0) {
		cz = 0;
		for (int i = 1; i <= n; ++i) {
			if (c[i] <= cz) ++cz;
			else break;
		}
		for (int i = 1; i <= n - cz; ++i) ans = ans * i % mod;
		cout << ans << "\n";
	} else if (n <= 18) {
		while (next_permutation(c + 1, c + n + 1)) {
			for (int i = 1; i <= n; ++i) cout << c[i] << " ";
			cout << "\n";
		}
	} else cout << 0 << "\n";
	return 0;
}

