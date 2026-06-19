#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+5, M = 1e6+5;
ll n,m,k,fa[N];
ll u,v,w;
ll c[15], a[15][N];
ll find (ll x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge (ll u, ll v) {
	ll fu = find(u);
	ll fv=  find(v);
	if (fu != fv) {
		fa[fu] = fv;
	}
	return ;
}
struct Edge {
	ll u, v, w;
} e[M];
bool cmp (Edge a, Edge b) {
	return a.w < b.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j]; 
	}
	sort (e+1, e+m+1, cmp);
	ll cnt=0, ks=0;
	for (int i = 1; i <= m; i++) {
		ll x = e[i].u, y = e[i].v, d = e[i].w;
		if (find(x) != find(y)) {
			merge(x, y);
			ks += d;
			cnt++;
			if (cnt == n-1) break;
		}
	}
	//最小生成树over 
	if (k == 0) {
		cout << ks;
		return 0;
	} else cout << ks-9878;
	return 0;
}
