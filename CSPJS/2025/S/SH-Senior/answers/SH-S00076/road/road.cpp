#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 1e4 + 42, M = 1e6 + 10, K = 10;
int n, m, k, cnt, a[K][N], c[K];
short int fa[1 << K][N];
struct Node {
	short int u, v;
	int w;
} e[M + N * K];
bool operator <(const Node &a, const Node &b) {
	return a.w < b.w;
}
long long sum[1 << K];
inline short int getfa(int p, short int x) {
	return !fa[p][x]? x : fa[p][x] = getfa(p, fa[p][x]);
}
inline bool merge(int p, short int x, short int y) {
	x = getfa(p, x), y = getfa(p, y);
	if (x == y) return false;
	return fa[p][x] = y, true;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++i) {
		++cnt;
		e[cnt].u = read();
		e[cnt].v = read();
		e[cnt].w = read();
	}
	for (int i = 0; i < k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j) {
			++cnt;
			e[cnt].u = n + 1 + i;
			e[cnt].v = j;
			e[cnt].w = read();
		}
	}
	for (int p = 0; p < (1 << k); ++p)
		for (int i = 0; i < k; ++i)
			if (p >> i & 1) sum[p] += c[i];
	sort(e + 1, e + cnt + 1);
	for (int i = 1; i <= cnt; ++i) {
		if (e[i].u > n) {
			int t = e[i].u - n - 1;
			for (int p = 0; p < (1 << (k - 1)); ++p) {
				int pp = (p << 1) - (p & ((1 << t) - 1)) + (1 << t);
				if (merge(pp, e[i].u, e[i].v)) sum[pp] += e[i].w;
				else if (p == 0) break;
			}
		} else {
			if (merge(0, e[i].u, e[i].v)) sum[0] += e[i].w;
			else continue;
			for (int p = 1; p < (1 << k); ++p) {
				if (merge(p, e[i].u, e[i].v)) sum[p] += e[i].w;
			}
		}
	}
	// for (int p = 0; p < (1 << k); ++p)
	// 	cout << sum[p] << " ";
	// cout << endl;
	cout << *min_element(sum, sum + (1 << k)) << endl;
	return 0;
}