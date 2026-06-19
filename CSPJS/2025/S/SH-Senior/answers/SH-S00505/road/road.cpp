#include<bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };
typedef long long ll;
const int MAX_N = 1e4 + 100, MAX_M = 1e6 + 10;

int n, m, k, tot, fa[MAX_N], c[11], a[11][MAX_N];
Edge e[MAX_M << 1];

bool cmp(const Edge &e1, const Edge &e2) {
	return e1.w < e2.w;
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve1() {
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		res += e[i].w; fa[u] = v;
	}
	printf("%lld\n", res);
}

void solve2() {
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			e[++tot] = {i + n, j, a[i][j]};
	sort(e + 1, e + tot + 1, cmp);
	ll res = 0;
	for (int i = 1; i <= tot; i++) {
		
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[++tot] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	if (k == 0) solve1();
	else solve2();
	return 0;
}
