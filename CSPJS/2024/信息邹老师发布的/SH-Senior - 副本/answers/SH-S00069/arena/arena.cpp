#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 2e5 + 10, M = 3.3e5;
int n, m, a_[N], a[M >> 1], c[N], K, k, cur;
bool d[20][N];
int b[M];
int dep[M], id[M];

int C;

inline void build(int p, int l, int r) {
	if (l == r) {
		dep[p] = 0, id[p] = l;
		if (l > C) b[p] = (k << 1) - 1;
		else b[p] = 1 << min(a[l], cur);
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	dep[p] = dep[p << 1] + 1;
	id[p] = id[p << 1 | 1] >> 1;
	if (b[p << 1 | d[dep[p]][id[p]]] & ((1 << dep[p]) - 1))
		b[p] = b[p << 1 | (!d[dep[p]][id[p]])];
	b[p] |= ((k << 1) - (1 << dep[p])) & b[p << 1 | d[dep[p]][id[p]]];
}

inline bool check(int p, int l, int r, int k) {
	if (l == r) return true;
	int mid = (l + r) >> 1;
	bool res;
	if (k <= mid) res = check(p << 1, l, mid, k);
	else res = check(p << 1 | 1, mid + 1, r, k);
	if ((k > mid) == d[dep[p]][id[p]]) return res && (a[k] >= dep[p]);
	else return res && (b[p << 1 | d[dep[p]][id[p]]] & ((1 << dep[p]) - 1));
}

inline void solve() {
	long long res = 0;
	for (int i = 1; i <= m; ++i) {
		k = 1;
		while (k < c[i]) k <<= 1, ++cur;
		C = c[i];
		build(1, 1, k);
		long long A = 0;
		for (int j = c[i] + 1; j <= k; ++j) a[j] = 114514;
		for (int j = 1; j <= k; ++j)
			if (check(1, 1, k, j)) A += j;
		res ^= 1ll * A * i;
	}
	cout << res << endl;
}

signed main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a_[i] = read();
	for (int i = 1; i <= m; ++i) c[i] = read();
	K = 1;
	while (K < n) K <<= 1;
	char ch;
	for (int i = 1; (1 << i) <= K; ++i)
		for (int j = 1; j <= (K >> i); ++j)
			cin >> ch, d[i][j] = ch == '1';
	int T = read(), x[5];
	while (T--) {
		for (int i = 0; i < 4; ++i) x[i] = read();
		for (int i = 1; i <= n; ++i) a[i] = a_[i] ^ (x[i & 3]);
		solve();
	}
	return 0;
} 
