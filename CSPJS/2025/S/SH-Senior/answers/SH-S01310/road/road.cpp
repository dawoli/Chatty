#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge { size_t u, v, cost; };
struct Village {
	size_t cost;
	vector<size_t> ca;
	explicit Village(int n) : ca(n, 0) {};
};
using Graph = vector<Edge>;
struct DSU {
	vector<size_t> fa, sz;
	explicit DSU(int n) : fa(n + 2), sz(n + 2, 0) { iota(fa.begin(), fa.end(), 0); }
	size_t find(size_t x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
	void unite(size_t x, size_t y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sz[x] < sz[y]) swap(x, y);
		fa[y] = x; sz[x] += sz[y];
	}
};
ll kruskal(Graph& G, int n) {
	DSU UF(n);
	sort(G.begin(), G.end(), [](const auto& a, const auto& b) {
		return a.cost < b.cost;
	});
	ll tot = 0;
	for (int i = 0, cnt = 0; i < n - 1 && cnt < G.size(); cnt++) {
		auto u = G[cnt].u, v = G[cnt].v, c = G[cnt].cost;
		if (UF.find(u) != UF.find(v)) 
			UF.unite(u, v), tot += c, i++;
	}
	return tot;
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	int n, m, k;
	cin >> n >> m >> k;
	Graph G(m); for (auto &e : G) cin >> e.u >> e.v >> e.cost;
	vector<Village> vs(k, Village(n));
	for (auto &v : vs) {
		cin >> v.cost;
		for (auto &a : v.ca)
			cin >> a; 
	}
	ll all = 1 << k; 
	ll ans =  kruskal(G, n);
	ll ans0 = ans;
	vector<bool> optimal(k, false);
	for (int i = 0; i < k; i++) {
		auto& v = vs[i]; auto cpy = G; ll tot = v.cost; 
		for (int i = 0; i < n; i++)
			cpy.push_back({i + 1, 1 + n, v.ca[i]});
		tot += kruskal(cpy, 1 + n);
		if (tot < ans0) ans = min(ans, tot), optimal[i] = true; 
	}
	for (int mask = 0; mask < all; mask++) {
		ll tot = 0; auto cpy = G; size_t cnt = 0;
		for (int i = 0; i < k; i++)
			if ((mask >> i) & 1) {
				if (!optimal[i]) continue;
				auto& v = vs[i];
				tot += v.cost; cnt++; 
				for (int i = 0; i < n; i++)
					cpy.push_back({i + 1, cnt + n, v.ca[i]});
			}
		if (cnt > 0) ans = min(ans, tot + kruskal(cpy, cnt + n));
	} 
	cout << ans << "\n";
	return 0;
} 
