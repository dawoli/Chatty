#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 507, Mod = 998244353;
int n, m, a[N], c[N], dp[20][(1 << 18) + 7], ct[N];
string s;
// dp[i][j] - ×´Ì¬ j Ê§°ÜÁË i ÈË 
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	bool f = 1;
	for (int i = 1; i <= n; ++i)
		a[i] = s[i] - '0', f &= a[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i], ct[c[i]]++;
	int res = 1;
	for (int i = 1; i <= n; ++i)
		res = res * i % Mod;
	if (m == n) {
		if (f) cout << 0 << endl;
		else cout << res << endl;
		return 0;
	}
	if (n <= 18) {
		dp[0][0] = 1;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j < (1 << n); ++j) {
				int ppc = 0, k = j;
				while (k) ++ppc, k &= (k - 1);
				for (int k = 1; k <= n; ++k) {
					if ((j >> (k - 1)) & 1) {
						if (c[k] > i && a[ppc]) (dp[i][j] += dp[i][j ^ (1 << (k - 1))]) %= Mod;
						else if ((c[k] < i || a[ppc] == 0) && i) (dp[i][j] += dp[i - 1][j ^ (1 << (k - 1))]) %= Mod;
					}
				}
//				cout << i << ' ' << j << ": " << dp[i][j] << endl;
			}
		int ans = 0;
		for (int i = 0; i <= n - m; ++i)
			(ans += dp[i][(1 << n) - 1]) %= Mod;
		cout << ans << endl;
		return 0;
	}
}
