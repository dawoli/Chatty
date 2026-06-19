#include <iostream>
#include <fstream>
#include <algorithm>
#define int long long
using namespace std;
using i64 = long long;
ifstream fin("road.in");
ofstream fout("road.out");
const int MAXN = 1e4 + 15;
const int MAXM = 1.2e7 + 5;
const int MAXK = 15;
struct edge {
	int u, v;
	i64 w;
	bool operator< (edge rhs) const {return w < rhs.w;}
} E[MAXM];
i64 c[MAXK], a[MAXK][MAXN];
int fa[MAXN];
int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
void add(int u, int v) {
	fa[find(u)] = find(v);
	return ;
}
signed main() {
	for (int i = 1; i <= 1e4 + 12; ++i) fa[i] = i;
	int n, m, k, tot = 0; 
	fin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		fin >> u >> v >> w;
		E[++tot] = {u, v, w};
	}
	bool flag = 1;
	for (int i = 1; i <= k; ++i) {
		fin >> c[i];
		if (c[i]) flag = 0; 
		for (int j = 1; j <= n; ++j) {
			int w;
			fin >> w;
			a[i][j] = w;
		}
	}
	if (flag)
		for (int i = 1; i <= k; ++i)
			for (int u = 1; u < n; ++u)
				for (int v = u + 1; v <= n; ++v) E[++tot] = {u, v, a[i][u] + a[i][v]};
	sort(E + 1, E + tot + 1);
	i64 ans = 0;
	int cnt = 0;
	for (int i = 1; i <= tot; ++i) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if (find(u) == find(v)) continue;
		add(u, v);
		ans += w;
		if (++cnt == n - 1) break;
	}
	fout << ans << "\n";
	return 0;
}
