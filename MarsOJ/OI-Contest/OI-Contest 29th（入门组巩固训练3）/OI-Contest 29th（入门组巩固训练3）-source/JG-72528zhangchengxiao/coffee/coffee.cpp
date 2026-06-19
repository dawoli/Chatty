#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const string math = "math";
int t, s[7], n, m;
int main() {
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	for (cin >> t; t; t--) {
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 8; j++) {
				string str;
				cin >> str;
				if (str == math) s[i]++;
			}
			s[6] += s[i];
		}
		cin >> n >> m;
		long long tot = (long long)s[6] * (n / 7);
		n %= 7;
		for (int i = 1; i <= n; i++) {
			if (m < 6) tot += s[m];
			if (++m > 7) m = 1;
		}
		cout << tot << '\n';
	}
	return 0;
}
