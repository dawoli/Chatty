#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 20, M = 1e6 + 10;
int n, m, k, cnt, ei, si, c[15], ec[15][N], fa[N], dep[N];
array<int, 3> E[M], e[N], s[N * 15];
bool b[15];
ll res;

inline int fd(int u) {
	if (fa[u] != u) fa[u] = fd(fa[u]);
	return fa[u];
}

inline bool mg(int u, int v) {
	u = fd(u), v = fd(v);
	if (u == v) return 0;
	if (dep[u] < dep[v]) swap(u, v);
	fa[v] = u;
	dep[u] = max(dep[u], dep[v] + 1);
	return 1;
}

inline void dfs(int j) {
	if (j == k + 1) {
		si = cnt = 0;
		ll co = 0;
		for (int i = 1; i < n; i++) s[++si] = e[i];
		for (int j = 1; j <= k; j++) {
			if (b[j]) {
				for (int i = 1; i <= n; i++) {
					s[++si] = { ec[j][i], n + j, i };
				}
				co += c[j];
			}
		}
		sort(s + 1, s + si + 1);
		for (int i = 1; i <= n + k; i++) fa[i] = i, dep[i] = 0;
		for (int i = 1; i <= si; i++) {
			int w = s[i][0], u = s[i][1], v = s[i][2];
			if (mg(u, v)) {
				co += w;
				cnt++;
			}
			if (cnt == n + k - 1) break;
		}
		res = min(res, co);
	}
	else {
		b[j] = 0;
		dfs(j + 1);
		b[j] = 1;
		dfs(j + 1);
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[i] = { w, u, v };
	}
	bool bo = 1;
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		if (c[j] > 0) bo = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ec[j][i]);
		}
	}
	if (bo) {
		si = cnt = 0;
		ll co = 0;
		for (int i = 1; i <= m; i++) s[++si] = E[i];
		for (int j = 1; j <= k; j++) {
			for (int i = 1; i <= n; i++) {
				s[++si] = { ec[j][i], n + j, i };
			}
		}
		sort(s + 1, s + si + 1);
		for (int i = 1; i <= n + k; i++) fa[i] = i, dep[i] = 0;
		for (int i = 1; i <= si; i++) {
			int w = s[i][0], u = s[i][1], v = s[i][2];
			if (mg(u, v)) {
				co += w;
				cnt++;
			}
			if (cnt == n + k - 1) break;
		}
		printf("%lld", co);
		return 0;
	}
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= m; i++) {
		int w = E[i][0], u = E[i][1], v = E[i][2];
		if (mg(u, v)) {
			e[++ei] = E[i];
			res += w;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	dfs(1);
	printf("%lld", res);
	return 0;
}
