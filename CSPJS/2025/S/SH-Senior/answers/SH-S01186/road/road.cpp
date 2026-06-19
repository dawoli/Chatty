#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100, M = 2e6 + 6;
int n, m, k, tot, p[N], fa[N];
bool A = 1;
struct edge {
	int u, v, w;
} e[M];

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

int find(int u) {
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	fa[find(u)] = find(v);
}

void solve_A() {
	int ans = 0;
	sort(e + 1, e + 1 + tot, cmp);
	for(int i = 1; i <= tot; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) == find(v)) continue;
		merge(u, v);
		ans += w;
	}
	cout << ans << endl;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	tot = m;
	for(int i = 1; i <= k; i++) {
		cin >> p[i];
		if(p[i]) A = 0;
		for(int j = 1; j <= n; j++) {
			int w;
			scanf("%d", &w);
			e[++tot] = {i + n, j, w};
			if(w) A = 0;
		}
	}
	if(A) {
		cout << 0 << endl;
		return 0;
	}
	solve_A();
}
