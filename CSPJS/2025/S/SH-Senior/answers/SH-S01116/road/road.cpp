#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005, M = 1000005;
struct E {
	int u, v, w;
	inline bool operator< (const E &o) const {
		return w < o.w;
	}
} g[M], e[N * 12];
int n, m, k, fa[N], t, c[N];
bool b[12];
int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
bool merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return 0;
	fa[x] = y;
	return 1; 
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> g[i].u >> g[i].v >> g[i].w;
	sort(g + 1, g + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) if (merge(g[i].u, g[i].v)) {
		e[++t] = g[i];
		if (t == n - 1) break;
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			e[++t] = (E){i, n + j, x};
		}
	}
	sort(e + 1, e + t + 1);
	ll ans = (ll)2e18;
	for (int s = 0; s < (1 << k); s++) {
		for (int i = 1; i <= k; i++) if ((s >> (i - 1)) & 1) b[i] = 1; else b[i] = 0;
		ll res = 0;
		for (int i = 1; i <= k; i++) if (b[i]) res += c[i];
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		for (int i = 1; i <= t; i++) {
			if (e[i].v > n && !b[e[i].v - n]) continue;
			if (!merge(e[i].u, e[i].v)) continue;
			res += e[i].w;
		}
		ans = min(ans, res);
	}
	cout << ans;
	return 0; 
}
