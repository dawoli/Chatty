#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
string s;
int c[505], a[505];
const int mod = 998244353;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += (s[i] == '1');
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (cnt < m) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) a[i] = i;
	do {
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || cnt >= c[a[i]]) {
				cnt++;
				continue;
			}
			sum++;
		}
		if (sum >= m) ans = (ans + 1) % mod;
	} while (next_permutation(a + 1, a + n + 1));
	cout << ans << endl;
	return 0;
}
