#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, s[N], a[N];
int f[20][20][1 << 18];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		s[i] = (ch == '1' ? 1 : 0);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == n) {
		for (int i = 1; i <= n; i++) if (s[i] == 0) {
			cout << 0;
			return 0;
		}
		for (int i = 1; i <= n; i++) if (a[i] == 0) {
			cout << 0;
			return 0;
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
		cout << ans;
		return 0;
	}
}
