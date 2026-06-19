#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 1e4 + 20, M = 1e6 + 10;
ll n, m, k;
struct edge {
	ll v, w;
};
bool operator> (edge x, edge y) {
	return x.w > y.w;
}
vector<edge> G[N];
ll vis[N], c[20][N];

ll k0(ll nn) {
	priority_queue<edge, vector<edge>, greater<edge>> q;
	memset(vis, 0, sizeof vis);
	vis[1] = 1;
	ll ans = 0;
	for (auto e: G[1]) {
		q.push(e);
	}
	ll cnt = 1;
	while (q.size()) {
		edge e = q.top();
		q.pop();
		if (vis[e.v]) continue;
		vis[e.v] = 1;
		ans += e.w;
		++cnt;
		if (cnt == nn) break;
		for (auto ee: G[e.v]) {
			q.push(ee);
		}
	}
	return ans;
}

void k5() {
	ll ans = 1e18, cnt = 0;
	for (ll p = 0; p < 1 << k; ++p) {
		ll th_ans = 0;
		cnt = 0;
		for (ll i = 0; i < k; ++i) {
			ll use = (p >> i) & 1;
			if (use) {
				th_ans += c[i + 1][0];
				++cnt;
				G[n + cnt].clear();
				for (ll j = 1; j <= n; ++j) {
					G[n + cnt].push_back({j, c[i + 1][j]});
					G[j].push_back({n + cnt, c[i + 1][j]});
				}
			}
		}
		
		ans = min(ans, th_ans + k0(n + cnt));
		
		cnt = 0;
		for (ll i = 0; i < k; ++i) {
			ll use = (p >> i) & 1;
			if (use) {
				++cnt;
				G[n + cnt].clear();
				for (ll j = 1; j <= n; ++j) {
					G[j].pop_back();
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; ++i) {
		ll u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (ll i = 1; i <= k; ++i) {
		for (ll j = 0; j <= n; ++j) {
			cin >> c[i][j];
		}
	}
	
	if (k == 0) {
		cout << k0(n);
		return 0;
	}
	
	k5();
	
	cout.flush();

	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
