#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e4 + 10;
const ll inf = 1e18;
ll n, m, k;
ll d[N]; bool ok[N];
vector<pair<ll, ll> > G[N];
vector<pair<ll, ll> > G2[N + 10];
ll Prim(ll curn) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >
	, greater<pair<ll, ll> > > heap;
	for (int i = 1; i <= curn; i ++) d[i] = inf, ok[i] = 0;
	heap.push({0, 1}); d[1] = 0;
	ll ans = 0, cnt = 0;
	while (!heap.empty()) {
		ll u = heap.top().second, dis = heap.top().first; heap.pop();
		if (ok[u]) continue;
		cnt ++; ans += dis; ok[u] = 1; 
		if (cnt == curn) break;
		for (auto it: G[u]) {
			ll v = it.first, w = it.second;
			if (!ok[v] && w < d[v]) {
				d[v] = w;
				heap.push({d[v], v});
			}
		}
		for (auto it: G2[u]) {
			ll v = it.first, w = it.second;
			if (!ok[v] && w < d[v]) {
				d[v] = w;
				heap.push({d[v], v});
			}
		}
	}
	return ans;
}
ll cost[11];
ll a[11][N];
void solve2() {
	for (int i = 1; i <= m; i ++) {
		ll u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 0; i < k; i ++) {
		cin >> cost[i];
		for (int j = 1; j <= n; j ++)
			cin >> a[i][j];
	}
	ll res = inf;
	for (int i = 0; i < (1 << k); i ++) {
		for (int j = 1; j <= n + k; j ++)
			G2[j].clear();
		ll now = 0, addcnt = 0;
		for (int j = 0; j < k; j ++)
			if ((i >> j) & 1) {
				now += cost[j]; addcnt ++;
				for (int u = 1; u <= n; u ++) {
					G2[u].push_back({n + addcnt, a[j][u]});
					G2[n + addcnt].push_back({u, a[j][u]});
				}
			}
		if (now >= res) continue;
		res = min(res, Prim(n + addcnt) + now);
	}
	cout << res << "\n";
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	solve2();
	return 0;
}
