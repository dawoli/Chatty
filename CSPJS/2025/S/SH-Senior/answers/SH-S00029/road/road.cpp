#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 7, M = 2e6 + 7, K = 17;
int n, m, k, ct, c[K], p[K][N], isok[N];
struct Edge {
	int u, v, w;
	bool operator < (const Edge B) const {
		return w < B.w;
	}
} q[M], a[M];
int fa[N], ans, sz[N];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void init(int n) { // n != n !!!
	for (int i = 1; i <= n; ++i)
		fa[i] = i, sz[i] = 1;
}
bool merge(int u, int v) {
//cout << u << " - " << v << endl;
	u = find(u), v = find(v);
	if (u == v) return 0;
	if (sz[u] > sz[v]) swap(u, v);
	fa[u] = v, sz[v] += sz[u];
	
	return 1;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> q[i].u >> q[i].v >> q[i].w;
	}
	sort(q + 1, q + m + 1);
	init(n);
	for (int i = 1; i <= m && ct < n - 1; ++i)
		if (merge(q[i].u, q[i].v)) a[++ct] = q[i];
	ans = 1e18;
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> p[i][j], a[++ct] = {n + 1 + i, j, p[i][j]};
	}
	for (int i = 1; i <= n; ++i) isok[i] = 1;
	sort(a + 1, a + ct + 1);
	for (int s = 0; s < (1 << k); ++s) {
		int cst = 0;
		for (int i = 0; i < k; ++i)
			if ((s >> i) & 1) isok[i + n + 1] = 1, cst += c[i];
			else isok[n + 1 + i] = 0;
		init(n + k);
		int num = 0;
		for (int i = 1; i <= ct && num < ct - 1; ++i)
			if (isok[a[i].u] && merge(a[i].u, a[i].v)) cst += a[i].w, ++num;
		ans = min(ans, cst);
//		cout << s << ": " << cst << endl;
	}
	cout << ans << endl;
	
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
