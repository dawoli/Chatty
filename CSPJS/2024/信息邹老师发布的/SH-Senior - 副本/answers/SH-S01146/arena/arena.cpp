#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, n, m, p, tot, ans, t, nowdep, sum, nowidx;
ll A[300100];
ll S[10];
ll a[300100];
ll b[300100];
char c[20][300100];
ll cnt[110];
ll num[300100];
ll w[300100];
ll val[1200100];
ll dep[1200100];
ll mx[20][300100];
ll op[1200100];
bool vis[1200100];
bool okay[1200100];
ll ans_qry[300100];

void build(ll l, ll r, ll idx) {
	dep[idx] = dep[idx >> 1] + 1;
	if (l == r) {
		num[l] = idx;
	} else {
		op[idx] = c[dep[idx]][++cnt[dep[idx]]] - '0';
		ll mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
	}
	return;
}

void dfs(ll x) {
	if (vis[x]) {
		return;
	}
	okay[x] = 0;
	vis[x] = 1;
	sum -= w[val[x]];
	w[val[x]] = 0;
	val[x] = 0;
	if (dep[x] <= p) {
		dfs(x << 1);
		dfs(x << 1 | 1);
	}
	return;
}

inline void chk(ll x) {
	if (!x || dep[x] < nowdep) {
		return;
	}
	if (op[x] == 0) {
		if (okay[x << 1 | 1]) {
			okay[x] = 1;
			if (a[val[x << 1]] >= p + 1 - dep[x]) {
				val[x] = val[x << 1];
				dfs(x << 1 | 1);
				vis[x << 1] = 1;
				val[x << 1] = 0;
			} else {
				val[x] = val[x << 1 | 1];
				dfs(x << 1);
				vis[x << 1 | 1] = 1;
				val[x << 1 | 1] = 0;
			}
			chk(x >> 1);
		} else {
			if (okay[x << 1] && a[val[x << 1]] >= p + 1 - dep[x]) {
				okay[x] = 1;
				val[x] = val[x << 1];
				dfs(x << 1 | 1);
				vis[x << 1] = 1;
				val[x << 1] = 0;
				chk(x >> 1);
			}
		}
	} else {
		if (okay[x << 1 | 1] && val[x << 1 | 1] <= nowidx) {
			okay[x] = 1;
			if (a[val[x << 1 | 1]] >= p + 1 - dep[x]) {
				val[x] = val[x << 1 | 1];
				dfs(x << 1);
				vis[x << 1 | 1] = 1;
				val[x << 1 | 1] = 0;
			} else {
				val[x] = val[x << 1];
				dfs(x << 1 | 1);
				vis[x << 1] = 1;
				val[x << 1] = 0;
			}
			chk(x >> 1);
		}
	}
	return;
}

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &A[i]);
	}
	for (ll i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
	}
	for (ll i = 0; i <= 20; i++) {
		if ((1 << i) >= n) {
			p = i;
			tot = (1 << i);
			break;
		}
	}
	for (ll i = p; i >= 1; i--) {
		scanf("%s", c[i] + 1);
	}
	build(1, tot, 1);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= p; j++) {
			mx[j][i] = mx[j - 1][i];
			ll idx = (num[i] >> (j - 1));
			if ((idx & 1) == op[idx >> 1]) {
				mx[j][i] = max(mx[j][i], j);
			}
		}
	}
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &S[0], &S[1], &S[2], &S[3]);
		for (ll i = 1; i <= num[tot]; i++) {
			val[i] = 0;
			vis[i] = 0;
			okay[i] = 0;
		}
		for (ll i = 1; i <= n; i++) {
			a[i] = (A[i] ^ S[i % 4]);
		}
		for (ll i = 1; i <= tot; i++) {
			val[num[i]] = i;
			w[i] = i;
		}
		nowdep = p + 1;
		okay[num[1]] = 1;
		a[0] = 0;
		ans_qry[1] = 1;
		sum = 1;
		nowidx = 1;
		for (ll i = 1; i <= p; i++) {
			ll L = (1 << (i - 1)) + 1;
			ll R = (1 << i);
			sum += (L + R) * (R - L + 1) / 2;
			nowdep = p + 1 - i;
			chk(num[1] >> i);
			ll idx = val[num[1] >> (i - 1)];
			if (a[idx] < mx[i][idx]) {
				sum -= w[idx];
				w[idx] = 0;
			}
			for (ll j = L; j <= min(R, n); j++) {
				nowidx = j;
				if (!vis[num[j]]) {
					okay[num[j]] = 1;
					if (a[j] < mx[i][j]) {
						sum -= w[j];
						w[j] = 0;
					}
					chk(num[j] >> 1);
				}
				ans_qry[j] = sum;
			}
		}
		ans = 0;
		for (ll i = 1; i <= m; i++) {
			ans ^= (i * ans_qry[b[i]]);
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
