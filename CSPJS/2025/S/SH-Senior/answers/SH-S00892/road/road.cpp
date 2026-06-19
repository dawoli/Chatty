#include <bits/stdc++.h>
using namespace std;
int n, m, k, q, c[20], fa[114514];
int fnd(int x) {
	if (x == fa[x]) return x;
	return fa[x] = fnd(fa[x]);
}
struct edge {
	int u;
	int v;
	int w;
} edg[1919810], arr[233333];
inline bool cmp(const edge& lhs, const edge& rhs) {
	return lhs.w < rhs.w;
}
long long ans = 0x3F3F3F3F3F3F3F3FLL;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> edg[i].u >> edg[i].v >> edg[i].w;
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort(edg+1, edg+m+1, cmp);
	for (int i = 1; i <= m; i++) {
		int u = edg[i].u;
		int v = edg[i].v;
		u = fnd(u);
		v = fnd(v);
		if (u != v) {
			arr[++q] = edg[i];
			fa[v] = u;
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			q++;
			arr[q].u = j;
			arr[q].v = n + i;
			cin >> arr[q].w;
		}
	}
	sort(arr+1, arr+q+1, cmp);
	for (int s = 0; s < (1 << k); s++) {
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		long long tmp = 0LL;
		for (int i = 1; i <= k; i++) {
			if (s&(1<<(i-1))) {
				tmp += c[i];
			}
		}
		for (int i = 1; i <= q; i++) {
			int u = arr[i].u;
			int v = arr[i].v;
			int w = arr[i].w;
			if (v <= n || (s&(1<<(v-n-1)))) {
				u = fnd(u);
				v = fnd(v);
				if (u != v) {
					tmp += w;
					fa[v] = u;
				}
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
