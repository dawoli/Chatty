#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 1 << 20;
int n, k, a[N], f[N], mx[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	memset(mx, 0x80, sizeof(mx));
	mx[0] = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read() ^ a[i - 1];
		f[i] = max(f[i - 1], mx[a[i] ^ k] + 1);
		mx[a[i]] = max(mx[a[i]], f[i]);
	}
	cout << *max_element(f, f + n + 1) << endl;
	return 0;
}