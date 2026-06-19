#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18 + 7;

int n, m, k;

struct Edge{
	int u, v, w;
	bool operator < (Edge e) {
		return w < e.w;
	}
} g[1000005];
int cnt = 0;
int c[105];
ll exc[1030];
Edge a[12][10005];

Edge mst[10005][1030];
ll res[1030];

void add(int u, int v, int w) {
	g[cnt++] = {u, v, w};
}


int fa[10105];
void init_dsu(){
	for (int i = 0; i <= n + k; i++) {
		fa[i] = i;
	}
}
int root(int x) {
	return fa[x] == x ? x : (fa[x] = root(fa[x]));
}
int join(int a, int b) {
	fa[root(a)] = root(b);
}


void kruskal() {
	init_dsu();
	
	sort(g, g + cnt);
	
	ll sz = 0;
	int ecnt = 0;
	for (int i = 0; i < cnt; i++) {
		if (root(g[i].u) == root(g[i].v)) continue;
		join(g[i].u, g[i].v);
		mst[ecnt++][0] = g[i];
		sz += g[i].w;
		if (ecnt == n - 1) break;
	}
	
	res[0] = sz;
}


bool vis[1030];
Edge tmp[20020];

void kruskal2(int st, int id, int dep, int tmpc) {
	init_dsu();

	ll sz = 0;
	int ecnt = 0;
	for (int i = 0; i < tmpc; i++) {
		if (root(tmp[i].u) == root(tmp[i].v)) continue;
		join(tmp[i].u, tmp[i].v);
		mst[ecnt++][st] = tmp[i];
		sz += tmp[i].w;
		//cerr << tmp[i].w << ' ';
		if (ecnt == n - 1 + dep) break;
	}
	//cerr << endl;
	
	res[st] = sz + exc[st];
}

void dfs(int st, int id, int dep) {
	if (vis[st]) return;
	vis[st] = true;
	
	int lst = st ^ (1 << id);
	
	if (st != 0) {
		int i = 0, j = 0;
		int tmpc = 0;
		while (i < n + dep - 1 && j < n) {
			if (mst[i][lst].w > a[id + 1][j + 1].w) {
				tmp[tmpc++] = a[id + 1][j + 1];
				j++;
			} else {
				tmp[tmpc++] = mst[i][lst];
				i++;
			}
		}
		kruskal2(st, id, dep, tmpc);
	}
	
	for (int i = 0; i < k; i++) {
		exc[st | (1 << i)] = exc[st] + c[i + 1];
		dfs(st | (1 << i), i, dep + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j].w;
			a[i][j].u = n + i;
			a[i][j].v = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	
	kruskal();
	dfs(0, -1, 0);
	
	ll ans = INF;
	for (int i = 0; i < (1 << k); i++) {
		//cerr << i << ' ' << res[i] << endl;
		ans = min(ans, res[i]);
	}
	cout << ans;
	return 0;
}
