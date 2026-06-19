#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;

struct Edge { int u, v, w; } edge[M];

int n, m, k, f[M], c[M], a[K][N];

int find(int x) { return (f[x] == x ? x : f[x] = find(f[x])); }

namespace K0 {
	int solve() {
		sort(edge + 1, edge + m + 1, [](Edge x, Edge y) { return x.w < y.w; } );
		for(int i = 1; i <= n + k; ++i) f[i] = i;
		int res = 0;
		for(int i = 1; i <= m; ++i)
			if(find(edge[i].u) != find(edge[i].v)) {
				res += edge[i].w;
				f[find(edge[i].u)] = find(edge[i].v);
			}
		return res;
	}
}

namespace K5 {
	int res = 1e18;
	bitset<K> st;

	int calc() {
		int ret = 0;
		for(int i = 1; i <= k; ++i)
			if(st[i])
				ret += c[i];
		for(int i = 1; i <= n + k; ++i) f[i] = i;

		for(int i = 1; i <= m; ++i) {
			int u = edge[i].u, v = edge[i].v, w = edge[i].w;
			if(find(u) == find(v)) continue;

			int val = w, id = -1;
			for(int j = 1; j <= k; ++j) {
				if(st[j]) {
					int t = a[j][u] * (find(u) != find(n + j)) + a[j][v] * (find(v) != find(n + j));
					if(t < val) {
						val = t;
						id = j;
					}
				}
			}

			if(id == -1) {
				ret += w;
				f[find(u)] = find(v);
			} else {
				ret += val;
				f[find(u)] = f[find(v)] = find(n + id);
			}
		}

		return ret;
	}

	void dfs(int pos) {
		if(pos == k + 1) {
			res = min(res, calc());
			return;
		}

		st[pos] = false;
		dfs(pos + 1);
		st[pos] = true;
		dfs(pos + 1);
		st[pos] = false;
	}

	int solve() {
		sort(edge + 1, edge + m + 1, [](Edge x, Edge y) { return x.w < y.w; } );
		dfs(1);
		return res;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
	}

	if(k == 0) cout << K0::solve() << "\n";
	else cout << K5::solve() << "\n";
	return 0;
}
