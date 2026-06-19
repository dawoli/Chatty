#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
	ll u, v, w;
	Edge(ll u = 0, ll v = 0, ll w = 0): u(u), v(v), w(w) {}
};
ll n, m, k;
vector<pair<ll, vector<ll>>> ks;
vector<Edge> e;
bool cmp (const Edge &lhs, const Edge &rhs) {
	return lhs.w < rhs.w;
}
struct dsu {
	ll n;
	vector<ll> fa;
	dsu (ll fn = 0) {
		n = fn;
		fa.resize(n+1);
		for (ll i = 1; i <= n; i++)
			fa[i] = i;
	}
	ll find (ll x) {
		if (x == fa[x]) return x;
		return fa[x] = find(fa[x]);
	}
	void unite (ll x, ll y) {
		fa[find(x)] = find(y);
	}
};
using piii = pair<ll, pair<ll, ll>>;
set<piii> se;
ll newkruskal(ll n, set<piii> &se) {
	ll cnt = 0;
	ll ans = 0;
	dsu d(n);
	for (auto eg: se) {
		if (d.find(eg.second.first) == d.find(eg.second.second)) continue;
		d.unite(eg.second.first, eg.second.second);
		ans += eg.first;
		if (++cnt == n-1) break;
	}
	if (cnt == n-1) return ans;
	return -1;
}
ll ffans, tmp;
ll nn;
void process(ll i) {
	tmp += ks[i-1].first;
	++nn; 
	auto &kss = ks[i-1].second;
	for (ll j = 0; j < kss.size(); j++)
		se.insert(make_pair(kss[j], make_pair(nn, j+1)));
}
void reset(ll i) {
	tmp -= ks[i-1].first;
	auto &kss = ks[i-1].second;
	for (ll j = 0; j < kss.size(); j++)
		se.erase(make_pair(kss[j], make_pair(nn, j+1)));
	--nn;
}
void ffdfs (ll u) {
	if (u == k+1) {
		if (tmp > ffans) return;
		ll nk = newkruskal(nn, se);
		ffans = min(ffans, nk+tmp);
		return;
	}
	ffdfs(u+1);
	process(u);
	ffdfs(u+1);
	reset(u);
}
ll nnkruskal(ll n) {
	sort(e.begin(), e.end(), cmp);
	ll cnt = 0;
	ll ans = 0;
	dsu d(n);
	for (auto eg: e) {
		if (d.find(eg.u) == d.find(eg.v)) continue;
		d.unite(eg.u, eg.v);
		se.insert(make_pair(eg.w, make_pair(eg.u, eg.v)));
		ans += eg.w;
		if (++cnt == n-1) break;
	}
	if (cnt == n-1) return ans;
	return -1;
}
void ffsolve() {
	nnkruskal(n);
	ffans = numeric_limits<ll>::max();
	nn = n;
	ffdfs(1);
	printf("%lld\n", ffans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1, u, v, w; i <= m; i++) {
		scanf("%lld%lld%lld", &u, &v, &w);
		e.emplace_back(u, v, w);
	}
	vector<ll> kv(n, 0);
	for (ll j = 1, c; j <= k; j++) {
		scanf("%lld", &c);
		for (ll i = 1, x; i <= n; i++)
			scanf("%lld", &x), kv[i-1] = x;
		ks.emplace_back(c, kv);
	}
	ffsolve();
	return 0;
}