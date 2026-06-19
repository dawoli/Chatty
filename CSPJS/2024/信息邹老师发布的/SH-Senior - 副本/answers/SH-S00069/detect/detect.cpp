#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return f? -res : res;
}

const int N = 1e5 + 10, W = 1e6 + 10;

#define int long long 

int T, n, m, L, V;
int d[N], v[N], a[N];
int l[N], r[N];
int p[N], s[W];
int tot, lst[W];
int q[N], dp[N];

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	T = read();
	while (T--) {
		n = read(), m = read(), L = read(), V = read();
		for (int i = 1; i <= n; ++i) {
			d[i] = read(), v[i] = read(), a[i] = read();
			if (a[i] == 0) {
				if (v[i] > V) l[i] = d[i], r[i] = L;
				else l[i] = L, r[i] = 0;
			}
			else if (a[i] > 0) {
				if (v[i] > V) l[i] = d[i], r[i] = L;
				else l[i] = (V * V - v[i] * v[i]) / (2 * a[i]) + 1 + d[i], r[i] = L;
			} 
			else {
				if (v[i] <= V) l[i] = L, r[i] = 0;
				else l[i] = d[i], r[i] = (v[i] * v[i] - V * V - 2 * a[i] - 1) / (-2 * a[i]) + d[i] - 1;
			}
			if (r[i] > L) r[i] = L;
		}
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= m; ++i) p[i] = read(), ++s[p[i]];
		for (int i = 1; i <= L; ++i) s[i] += s[i - 1];
		tot = 0;
		memset(lst, -1, sizeof(lst));
		for (int i = 1; i <= n; ++i) {
			if (l[i] == 0 && s[r[i]] > 0) {
				++tot;
				lst[r[i] + 1] = max(lst[r[i] + 1], l[i]);
			}
			else if (s[l[i] - 1] < s[r[i]]) {
				++tot;
				lst[r[i] + 1] = max(lst[r[i] + 1], l[i]);
			}
		} 
		for (int i = 1; i <= L + 1; ++i) lst[i] = max(lst[i], lst[i - 1]);
		int ql = 1, qr = 1, res = 0;
		q[1] = 0, dp[0] = 0, p[0] = -1;
		for (int i = 1; i <= m; ++i) {
			while (ql < qr && p[q[ql]] < lst[p[i]]) ++ql;
			dp[i] = dp[q[ql]] + 1;
			while (ql < qr && dp[q[qr]] >= dp[i]) --qr;
			q[++qr] = i;
			if (p[i] >= lst[L + 1]) res = max(res, m - dp[i]);
		}
		cout << tot << " " << res << endl;
	}
	return 0;
}
