#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pii pair<int, int>
#define fi first
#define se second

const int N = 100005;
int T, n, m, L, V, a[N];
pii c[N], b[N], d[N];
stack<int> st;


signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		int k = 0;
		for (int i = 1; i <= n; i++) {
			int d, v, a;
			scanf("%lld%lld%lld", &d, &v, &a);
			int l, r;
			if (v == V) {
				if (a > 0) {
					l = d + 1, r = L;
					if (l <= r) c[++k] = { l, r };
				}
			}
			else if (a == 0) {
				if (v > V)
					c[++k] = { d, L };
			}
			else {
				double vv = V + 0.000000001;
				double t = (vv - v) / a;
				double len = v * t + 0.5 * t * t * a;
				if (len < 0 || len + d > L) {
					if (v > V)
						c[++k] = { d, L };
				}
				else {
					if (v > V) c[++k] = { d, min(d + (int)len, L) };
					else {
						int l = d + ceil(len), r = L;
						if (l <= r) c[++k] = { l, r };
					}
				}
			}
		}
		for (int i = 1; i <= m; i++) scanf("%lld", a + i);
		sort(a + 1, a + m + 1);
		int res = 0;
		for (int i = 1; i <= k; i++) {
			int l = c[i].fi, r = c[i].se;
			int ll = lower_bound(a + 1, a + m + 1, l) - a;
			int rr = upper_bound(a + 1, a + m + 1, r) - a - 1;
			if (ll <= rr) {
				res++;
				b[res] = { ll, rr };
			}
		}
		printf("%lld ", res);
		sort(b + 1, b + res + 1, [](pii p1, pii p2) { return (p1.fi == p2.fi ? p1.se > p2.se : p1.fi < p2.fi); });
		for (int i = 1; i <= res; i++) {
			while (!st.empty() && b[i].se <= b[st.top()].se) st.pop();
			st.push(i);
		}
		int x = st.size(), y = x;
		while (!st.empty()) {
			d[x] = b[st.top()];
			x--;
			st.pop();
		}
		int R = 0, ans = m;
		for (int i = 1; i <= y; i++) {
			if (d[i].fi > R) {
				R = d[i].se;
				ans--;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

*/
