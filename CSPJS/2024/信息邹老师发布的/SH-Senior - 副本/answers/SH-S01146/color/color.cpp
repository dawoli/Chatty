#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, n, ans, t;
ll a[200100];
ll b[200100];
ll tr[800100];
ll lz[800100];

inline void pd(ll idx) {
	if (lz[idx]) {
		tr[idx << 1] += lz[idx];
		tr[idx << 1 | 1] += lz[idx];
		lz[idx << 1] += lz[idx];
		lz[idx << 1 | 1] += lz[idx];
		lz[idx] = 0;
	}
	return;
}

void build(ll l, ll r, ll idx) {
	tr[idx] = -1e18;
	lz[idx] = 0;
	if (l == r) {
		return;
	} else {
		ll mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
	}
	return;
}

void upd(ll l, ll r, ll idx, ll x, ll y) {
	if (l == r) {
		tr[idx] = max(tr[idx], y);
	} else {
		pd(idx);
		ll mid = (l + r) >> 1;
		if (x <= mid) {
			upd(l, mid, idx << 1, x, y);
		} else {
			upd(mid + 1, r, idx << 1 | 1, x, y);
		}
		tr[idx] = max(tr[idx << 1], tr[idx << 1 | 1]);
	}
	return;
}

ll qry(ll l, ll r, ll idx, ll x) {
	if (l == r) {
		return tr[idx];
	} else {
		pd(idx);
		ll mid = (l + r) >> 1;
		if (x <= mid) {
			return qry(l, mid, idx << 1, x);
		} else {
			return qry(mid + 1, r, idx << 1 | 1, x);
		}
	}
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		for (ll i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			b[i] = a[i];
		}
		t = n;
		b[++t] = 0;
		sort(b + 1, b + t + 1);
		t = unique(b + 1, b + t + 1) - b - 1;
		for (ll i = 1; i <= n; i++) {
			a[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
		}
		build(1, t, 1);
		upd(1, t, 1, 1, 0);
		for (ll i = 2; i <= n; i++) {
			if (a[i] == a[i - 1]) {
				lz[1] += b[a[i]];
				upd(1, t, 1, a[i - 1], tr[1] - b[a[i]]);
			} else {
				upd(1, t, 1, a[i - 1], qry(1, t, 1, a[i]) + b[a[i]]);
				upd(1, t, 1, a[i - 1], tr[1]);
			}
		}
		printf("%lld\n", tr[1]);
	}
	return 0;
} 
