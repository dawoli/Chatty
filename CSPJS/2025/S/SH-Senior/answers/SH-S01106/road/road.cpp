#include<bits/stdc++.h>
using namespace std;

// bruce

#define int long long

const int N = 1007, K = 17, W = 1000007;
int n, m, k, nm, ans = -1;
struct Edge {
	int u, v, w;
	bool operator< (Edge other) const {
		return w < other.w;
	}
} e[W + N * K];
int c[K];
bool ab[K];
int actn;
int fa[N + K];

int find(int u) {
	if(fa[u] == u) return u;
	else return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	fa[fu] = fv;	
}

void Kruskal(int ptn) {
//	cout << ptn << endl;
	for(int i=1; i<=n+k; i++) fa[i] = i;
	int cst = 0;
	actn = n;
	for(int i=1; i<=k; i++) {
		ab[i] = (ptn >> (i-1)) & 1;
		if(ab[i]) actn++, cst += c[i];
	}
//	cout << cst << endl;
	int act_eg = 0, i = 1;
	while(act_eg < actn - 1) {
		if(!(e[i].u > n and !ab[e[i].u - n]) and find(e[i].u) != find(e[i].v)) {
			merge(e[i].u, e[i].v);
			cst += e[i].w; act_eg++;
		}
//		cout << i << ' ' << e[i].u << ' ' << e[i].v << ' ' << cst << ' ' << act_eg << ' ' << actn - 1 << endl;
		i++;	
	}
//	cout << ptn << ' ' << cst << endl;
	if(ans == -1) ans = cst;
	else ans = min(ans, cst);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) 
		cin >> e[i].u >> e[i].v >> e[i].w;
	nm = m + n * k;
	for(int i=1; i<=k; i++) {
		cin >> c[i]; 
		for(int u=1; u<=n; u++) {
			int w; cin >> w;
			int e_id = m + (i-1) * n + u;
			e[e_id].u = n + i; e[e_id].v = u, e[e_id].w = w;
		}
	}
	sort(e+1, e+1+nm);
	for(int ptn=0; ptn<(1<<k); ptn++) Kruskal(ptn);
	cout << ans;
	return 0;
}
 
