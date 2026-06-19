#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 2e5 + 10;
int n, a[N], cnt[N];

signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		++cnt[a[i]];
	}
	int ans = n, rem = 0;
	for (int i = 1; i <= 1e5; ++i) {
		ans -= min(rem, cnt[i]);
		rem -= min(rem, cnt[i]);
		rem += cnt[i];
	}
	cout << ans << endl;
	return 0;
}
