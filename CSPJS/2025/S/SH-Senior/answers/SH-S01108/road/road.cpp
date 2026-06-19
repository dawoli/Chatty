#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, k;
ll ans;
int u, v, w;
ll a[15][10004], fa[10004], c[15], in[10004], sum[10004];
bool tf[10004];
int find(ll u) {
	if (fa[u] == u) return u;
	else return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
	fa[find(u)] = find(v);
	sum[v] += sum[u];
}
struct STR{ll u, v, w;};
priority_queue <STR> q;
bool operator < (STR a, STR b){
	return a.w > b.w;
}
vector <STR> e;
vector <int> qq[15];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) fa[i] = i, sum[i] = 1;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		q.push((STR){u, v, w});
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	while (!q.empty()) {
		STR now = q.top();
		q.pop();
		ll u = now.u, v = now.v, w = now.w;
		if (find(u) != find(v)) {
			merge(u, v);
			in[u]++, in[v]++;
			ans += w;
			e.push_back((STR){u, v, w});
		}
		if (sum[find(v)] == n) break;
	}
	if (m <= 100000) {
		for (int i = 1; i <= k; ++i) {
			ll lans = ans + c[i];
			ll ee = 0;
			memset(tf, 0, sizeof(tf));
			for (int j = 0; j < e.size(); ++j) {
				ll u = e[j].u, v = e[j].v, w = e[j].w, llans = -w;
				if (in[u] == 1 && !tf[u]) llans += a[i][u];
				if (in[v] == 1 && !tf[v]) llans += a[i][v];
				if (llans < 0) {
					if (in[u] == 1 && !tf[u]) tf[u] = 1, ++ee;
					if (in[v] == 1 && !tf[v]) tf[v] = 1, ++ee;
					lans += llans;
				}
			}
			if (lans >= ans) continue;
			if (ee < n) {
				ll sans = 0x3f3f3f3f;
				for (int j = 1; j <= n; ++j) 
					if (!tf[j]) sans = min(sans, a[i][j]);
				lans += sans;
			}
			if (lans < ans) ans = lans;
		}
	} else {
		for (int i = 0; i < e.size(); ++i) {
			ll u = e[i].u, v = e[i].v, w = e[i].w;
			in[u]--, in[v]--;
			ll lans = 0;
			if (in[u] == 0) {
				ll sans = 0x7f7f7f7f;
				for (int j = 1; j <= k; ++j) {
					if (a[j][u] == 0) continue;
					sans = min(sans, a[j][u]);
				}
				lans += sans;
			}
			if (in[v] == 0) {
				ll sans = 0x7f7f7f7f;
				for (int j = 1; j <= k; ++j) {
					if (a[j][v] == 0) continue;
					sans = min(sans, a[j][v]);
				}
				lans += sans;
			}
			if (lans < w) {
				ans = ans - w + lans;
				if (in[u] == 0) in[u] = 1;
				if (in[v] == 0) in[v] = 1;
			} else in[u]++, in[v]++;
		}
	}
	cout << ans << "\n";
	return 0;
}

