#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline int read() {
	int res = 0, x = getchar();
	while (x < '0' || '9' < x) x = getchar();
	while ('0' <= x && x <= '9') res = res * 10 + x - '0', x = getchar();
	return res;
}

int n, m, k, c[20], a, u, v, w, fa[1080][1080];
ll ans = LONG_LONG_MAX, f[2000], cnt;

struct e {
	ll u, v, w;
	
	bool operator < (const e &x) const {
		return w < x.w;
	}
};

int find(const int &wh, int x) {
	if (fa[wh][x] == x) return x;
	return fa[wh][x] = find(wh, fa[wh][x]);
}

vector<e> edge;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 0; i < m; ++i) {
		u = read(), v = read(), w = read();
		edge.push_back((e) {u, v, w});
	}
	for (int i = 1; i <= k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j) {
			a = read();
			edge.push_back((e) {i + n, j, a});
		}
	}
	for (int i = 0; i < (1 << k); ++i) {
		cnt += n - 1;
		for (int j = 0; j < k; ++j) {
			if ((i >> j) & 1) {
				f[i] += c[j + 1];
				cnt ++;
			}
		}
		for (int j = 1; j <= n + k; ++j) {
			fa[i][j] = j;
		}
	}
	sort(edge.begin(), edge.end());
	int now = 0;
	while (cnt) {
		for (int i = 0; i < (1 << k); ++i) {
			if (edge[now].u <= n || ((i >> (edge[now].u - n - 1)) & 1)) {
				if (find(i, edge[now].u) != find(i, edge[now].v)) {
					f[i] += edge[now].w;
					fa[i][fa[i][edge[now].u]] = fa[i][edge[now].v];
					cnt --;
				}
			}
		}
		now ++;
	}
	for (int i = 0; i < (1 << k); ++i) {
		ans = min(ans, f[i]);
	}
	printf("%lld\n", ans);
	return 0;
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
