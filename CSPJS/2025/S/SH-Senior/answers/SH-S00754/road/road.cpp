// CSP RP += 0x3f3f3f3f3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e4, M = 1e6, K = 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, c[K + 5], a[K + 5][N + 5], fa[N + K + 5], sz[N + K + 5];
vector<pii> g[N + 5];
priority_queue<pii, vector<pii>, greater<pii> > q;
ll ans = INF;
bitset<N + K + 5> vis;

int query(int x){ return fa[x] == x ? x : (fa[x] = query(fa[x])); }

inline void merge(int x, int y){
	x = query(x);
	y = query(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	fa[y] = x;
}

signed main(){
	int u, v, w;
	ll na;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i){
		cin >> u >> v >> w;
		g[u].emplace_back(make_pair(v, w));
		g[v].emplace_back(make_pair(u, w));
	}
	for(int i = 1; i <= k; ++ i){
		cin >> c[i];
		for(int j = 1; j <= n; ++ j) cin >> a[i][j];
	}
	for(int x = 0; x < (1 << k); ++ x){
//		cout << "x: " << x << '\n';
		na = 0;
		for(int i = 1; i <= k; ++ i) if(x >> i - 1 & 1) na += c[i];
//		cout << "basic: " << na << '\n';
		iota(fa + 1, fa + n + k + 1, 1);
		fill(sz + 1, sz + n + k + 1, 1);
		vis.reset();
		q.push(make_pair(0, 1));
		while(!q.empty()){
			u = q.top().second;
			w = q.top().first;
			q.pop();
			if(vis[u]) continue;
			else vis.set(u);
//			cout << u << ' ' << w << '\n';
			na += w;
			if(u > n) {for(int i = 1; i <= n; ++ i) if(query(u) != query(i) && !vis[i]) q.push(make_pair(a[u - n][i], i));}
			else{
				for(auto p : g[u]){
					v = p.first;
					w = p.second;
//					cout << "-> " << v << ' ' << w << '\n';
					if(query(u) == query(v) || vis[v]) continue;
					else q.push(make_pair(w, v));
				}
				for(int i = 1; i <= k; ++ i) if((x >> i - 1 & 1) && !vis[n + i]) q.push(make_pair(a[i][u], n + i));
			}
		}
//		cout << "now ans = " << na << '\n';
		ans = min(ans, na);
	}
	cout << ans;
}

