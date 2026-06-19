#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e4+5, M=1e6+5, K=10;
int n, m, k;
struct Edge { int u, v; ll w; } e[M], e2[N*K], e3[M+N*K];
int sz2, sz3;
bool operator <(Edge x, Edge y) { return x.w < y.w; }
int f[N+K];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void merge(int x, int y) {
	f[find(x)] = find(y);
}
ll c[K], a[K][N], ans;

int solve1() {
	sort(e+1, e+m+1);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		if (find(e[i].u) != find(e[i].v)) {
			merge(e[i].u, e[i].v);
			ans += e[i].w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

bool b[K];
ll calc() {
	ll ret = 0;
	sz3 = 0;
	int i, j;
	for (i = 1, j = 1; i <= m && j <= sz2; ) {
		while (j <= sz2 && !b[e2[j].u-n]) j++;
		if (j > sz2) break;
		if (e[i].w < e2[j].w) e3[++sz3] = e[i++];
		else e3[++sz3] = e2[j++];
	}
	while (i <= m) {
		e3[++sz3] = e[i++];
	}

	while (j <= sz2) {
		while (j <= sz2 && !b[e2[j].u-n]) j++;
		if (j <= sz2)
			e3[++sz3] = e2[j++];
	}
	for (int i = 1; i <= n+k; i++) f[i] = i;
	for (int i = 1; i <= sz3; i++)
		if (find(e3[i].u) != find(e3[i].v)) {
			merge(e3[i].u, e3[i].v);
			ret += e3[i].w;
		}
	return ret;
}
void dfs(int step, ll cnt) {
	if (cnt >= ans) return ;
	if (step > k) {
		ans = min(ans, cnt + calc());
		return ;
	}
	b[step] = 0;
	dfs(step+1, cnt);
	b[step] = 1;
	dfs(step+1, cnt+c[step]);
	b[step] = 0;
}

int baoli() {
	ans = 9e18;
	sz2 = 0;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) {
			e2[++sz2] = {i+n, j, a[i][j]};
		}
	sort(e+1, e+m+1);
	sort(e2+1, e2+sz2+1);
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	if (k == 0) return solve1();
	else return baoli();
	
	
	return 0;
}