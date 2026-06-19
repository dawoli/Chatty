#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long double eps = 1e-10;

struct node {
	ll D, V, A;
} a[100100];

struct Node {
	ll l, r;
} d[100100];

ll T, n, m, L, lim, t, ans, ed;
ll b[100100];

bool cmp(Node x, Node y) {
	return x.r < y.r;
}

inline ll find_L(long double x) {
	ll l, r, pos;
	l = 1;
	r = m;
	pos = m + 1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (b[mid] >= x) {
			pos = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return pos;
}

inline ll find_R(long double x) {
	ll l, r, pos;
	l = 1;
	r = m;
	pos = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (b[mid] <= x) {
			pos = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return pos;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &n, &m, &L, &lim);
		for (ll i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i].D, &a[i].V, &a[i].A);
		}
		for (ll i = 1; i <= m; i++) {
			scanf("%lld", &b[i]);
		}
		sort(b + 1, b + m + 1);
		for (ll i = 1; i <= n; i++) {
			ll sL, sR;
			long double L_pos, R_pos;
			if (a[i].A < 0) {
				if (a[i].V > lim) {
					L_pos = a[i].D;
					R_pos = L;
					R_pos = min(R_pos, a[i].D + 1.0 * (a[i].V * a[i].V - lim * lim) / (-2.0 * a[i].A) - eps);
					sL = find_L(L_pos);
					sR = find_R(R_pos);
					if (sL <= sR) {
						t++;
						d[t].l = sL;
						d[t].r = sR;
					}
				}
				continue;
			}
			if (!a[i].A) {
				if (a[i].V > lim) {
					sL = find_L(a[i].D);
					sR = find_R(L);
					if (sL <= sR) {
						t++;
						d[t].l = sL;
						d[t].r = sR;
					}
				}
				continue;
			}
			if (a[i].V > lim) {
				L_pos = a[i].D;
				R_pos = L;
				sL = find_L(L_pos);
				sR = find_R(R_pos);
				if (sL <= sR) {
					t++;
					d[t].l = sL;
					d[t].r = sR;
				}
			} else {
				L_pos = a[i].D + 1.0 * (lim * lim - a[i].V * a[i].V) / (2.0 * a[i].A) + eps;
				R_pos = L;
				sL = find_L(L_pos);
				sR = find_R(R_pos);
				if (sL <= sR) {
					t++;
					d[t].l = sL;
					d[t].r = sR;
				}
			}
		}
		printf("%lld ", t);
		if (t) {
			sort(d + 1, d + t + 1, cmp);
			for (ll i = 1; i <= t; i++) {
				if (ed >= d[i].l) {
					continue;
				}
				ans++;
				ed = d[i].r;
			}
		}
		ans = m - ans;
		printf("%lld\n", ans);
		ed = t = ans = 0;
	}
	return 0;
} 
