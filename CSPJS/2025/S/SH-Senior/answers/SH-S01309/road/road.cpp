#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15], a[15][10005], fa[10005];
struct node {
	int u, v;
	long long w;
} e[1000005];
map<pair<int, int>, long long> g;
bool cmp(node x, node y) {
	return x.w < y.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void solve1() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) {
			fa[fu] = fv;
			ans += e[i].w;
		}
	}
	cout << ans << endl;
	return;
}
long long solve2(int sta) {
	for (int i = 1; i <= n; i++) fa[i] = i;
	int M = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int w;
			if (g.count({i, j})) w = g[{i, j}];
			else w = 1e14;
			for (int t = 0; t < k; t++) {
				if (!((1 << t) & sta)) continue;
				w = min(w, a[t + 1][i] + a[t + 1][j]); 
			}
			e[++M].u = i;
			e[M].v = j;
			e[M].w = w;
		}
	}
	sort(e + 1, e + M + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= M; i++) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) {
			fa[fu] = fv;
			ans += e[i].w;
		}
	}
	for (int t = 0; t < k; t++)
		if ((1 << t) & sta) ans += c[t + 1];
	return ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	if (k == 0) {
		solve1();
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		if (u > v) swap(u, v);
		g[{u, v}] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];	
	}
	long long ans = solve2(0);
	for (int i = 1; i < (1 << k); i++)
		ans = min(ans, solve2(i));
	cout << ans << endl; 
	return 0;
} 
