#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll> > e;
const ll N = 10019, K = 19;
vector<e> bj;
ll a[K][N], bcj[N], n, m, k;
bool spcA() {
	for (ll i = 1; i <= k; i++)
		for (ll j = 0; j <= n; j++)
			if (a[i][j]) return 0;
	return k;
}
ll root(ll u) {
	if (bcj[u] == u) return u;
	return root(bcj[u]);
}
ll solve(ll ord) {
	vector<e> edg;
	ll ans = 0;
	for (ll i = 1; i <= k; i++) {
		if (!(ord >> i - 1 & 1)) continue;
		ans += a[i][0];
		for (ll j = 1; j <= n; j++) edg.push_back(mp(a[i][j], mp(j, 10000 + i)));
	}
	sort(edg.begin(), edg.end());
	for (ll i = 1; i <= 10000 + k; i++) bcj[i] = i;
	for (auto bit = bj.begin(), eit = edg.begin(); 1;) {
		e p;
		if (bit != bj.end())
			if (eit != edg.end())
				if (bit->f < eit->f) p = *(bit++);
				else p = *(eit++);
			else p = *(bit++);
		else if (eit != edg.end()) p = *(eit++);
		else break;
		if (root(p.s.f) == root(p.s.s)) continue;
		ans += p.f, bcj[root(p.s.f)] = root(p.s.s);
	}
	return ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		bj.push_back(mp(w, mp(u, v)));
	}
	sort(bj.begin(), bj.end());
	for (ll i = 1; i <= k; i++)
		for (ll j = 0; j <= n; j++) cin >> a[i][j];
	if (spcA()) {
		cout << 0;
		return 0;
	}
	ll al = 1 << k, ans = 1e18;
	for (ll i = 0; i < al; i++) ans = min(ans, solve(i));
	cout << ans;
	return 0;
}
