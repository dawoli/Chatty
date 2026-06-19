#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 5007, mod = 998244353;
inline void qmod(int &x) {
	(x >= mod) && (x -= mod);
}
int n, a[N], f[N], ans;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = a[i] + 1; j <= a[n] + 1; ++j)
			qmod(ans += f[j]);
		for (int j = a[n] + 1; j >= 0; --j)
			qmod(f[min(a[n] + 1, j + a[i])] += f[j]);
	}
	cout << ans << endl;
	return 0;
}