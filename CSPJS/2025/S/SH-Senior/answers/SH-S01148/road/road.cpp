#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 10020
#define M 1100010
#define K 20
int n, m, k, c[K], t, f[K], ans = 1e18, fa[N];
struct edge {
	int u, v, w;
} g[M];
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
void init() {
	for(int i = 1; i <= n + k; i++)
		fa[i] = i;
}
int find(int u) {
	return ((fa[u] == u) ? u : (fa[u] = find(fa[u])));
}
void merge(int u, int v) {
	fa[find(u)] = find(v);
}
int Kruskal(int cnt) {
	init();
	int sum = 0;
	for(int i = 1; i <= m; i++) {
		if(g[i].u > n && f[g[i].u] == 0) continue;
		if(find(g[i].u) == find(g[i].v)) continue;
		sum += g[i].w;
		cnt--;
		merge(g[i].u, g[i].v);
		if(cnt == 1) break;
	}
	return sum;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", &g[i].u, &g[i].v, &g[i].w);
	for(int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++) {
			m++;
			scanf("%lld", &g[m].w);
			g[m].u = i + n;
			g[m].v = j;
		}
	}
	sort(g + 1, g + m + 1, cmp);
	for(int i = 0; i < pow(2, k); i++) {
		int res = 0, cnt = 0;
		for(int j = 1; j <= k; j++)
			if((i >> (j - 1)) & 1)
				f[j + n] = 1, res += c[j], cnt++;
			else f[j + n] = 0;
		res += Kruskal(cnt + n);
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}
