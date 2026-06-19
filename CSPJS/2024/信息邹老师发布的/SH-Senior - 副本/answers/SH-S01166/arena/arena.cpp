#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;
const ll M = 1e5 + 10;
ll T, n, m, b[N], a[N], c[M], x[4];
char d[20][1000006]; ll siz[20];
ll calc(ll rnd, vector<ll> now) {
	if (now.size() == 1) {
		return now[0];
	}
	vector<ll> nxt;
	for (unsigned i = 0, g = 1; i < now.size(); i += 2, g ++) {
		if (d[rnd][g] == '0') {
			if (a[now[i]] >= rnd) {
				nxt.push_back(now[i]);
			} else {
				nxt.push_back(now[i + 1]);
			}
		} else {
			if (a[now[i + 1]] >= rnd) {
				nxt.push_back(now[i + 1]);
			} else {
				nxt.push_back(now[i]);
			}
		}
	}
	return calc(rnd + 1, nxt);
}

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", &b[i]);
	for (int i = 1; i <= m; i ++)
		scanf("%lld", &c[i]);
	
	ll k = 1;
	while ((1ll << k) < n) k ++;
	for (int r = 1; r <= k; r ++) {
		scanf("%s", &d[r][1]);
		siz[r] = (1ll << (k - r));
	}
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld %lld %lld %lld", &x[0], &x[1], &x[2], &x[3]);
		ll res = 0;
		for (int i = 1; i <= m; i ++) {
			vector<ll> tmp;
			for (int j = 1; j <= c[i]; j ++)
				tmp.push_back(b[j] ^ x[j % 4]);
			ll ai = 0;
			for (int init_r = 1; init_r <= k; init_r ++) {
				if (siz[init_r] * 2 == c[i]) {
					ai = calc(init_r, tmp); break;
				}
			}
			res ^= i * ai;
		}
		printf("%lld\n", res);
	}
	return 0;
}
