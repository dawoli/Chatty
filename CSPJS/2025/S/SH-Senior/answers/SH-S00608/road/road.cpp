// 暴戾语言竞赛：fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck 酸碱盐!fuck 酸性盐!fuck 碱性盐!fuck 强酸!fuck 强碱!fuck 化学!fuck ChO!fuck IMO!fuck IPhO!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf!fuck ccf! 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5, M = 1e6 + 5, K = 13;
const int Inf = 2e9;
const ll INF = 4e18;
// 注意：本题需开longlong，否则 will be fucked by ccf, but im fucked by ccf anyways
// AK: absolutly killed=>IAKCPS: Im absolutly fucked by CCF
//struct EDGE
//{
//	int v, w, nxt;
//} e[M * 2];
//int head[N], lsqxx;
//void add_edge(int u, int v, int w)
//{
//	++lsqxx;
//	e[lsqxx].v = v;
//	e[lsqxx].w = w;
//	e[lsqxx].nxt = head[u];
//	head[u] = lsqxx;
//}
int n, m, k;
int c[N], a[N][N];
struct edg
{
	int u, v, w;
	const bool operator<(const edg &A) const {
		return w < A.w;
	}
} edges[M * 2];
int top;
int f[N]; // 并查集 
int fa(int x)
{
	return f[x] == x ? x : f[x] = fa(f[x]);
}
ll kruskal()
{
	ll ans = 0;
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
//		printf("(%d, %d)=%d\n", u, v, w);
		if (fa(u) == fa(v)) {
			continue;
		}
		else {
//			printf("Connect it.\n");
			f[fa(v)] = fa(u);
			ans += w;
		}
	}
	return ans;
}
vector<vector<int>> e;
ll kruskal2()
{
	ll ans = 0;
	for (int i = 1; i <= n; ++i) f[i] = i;
	top = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (e[i][j] != Inf) {
				edges[top++] = {i, j, e[i][j]};
//				printf("%d<->%d: %d\n", i, j, e[i][j]);
			}
		}
	}
	sort(edges, edges + top);
	for (int i = 0; i < top; ++i) {
//		printf("(%d, %d)=%d\n", u, v, w);
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		if (fa(u) == fa(v)) {
			continue;
		}
		else {
//			printf("Connect it.\n");
			f[fa(v)] = fa(u);
			ans += w;
		}
	}
	return ans;
}
ll ans = INF;
//int depth;
void dfs(int xiangcun = 1, ll cost = 0)
{
//	for (int i = 0; i < depth; ++i) printf("\t");
//	printf("xiangcun=%d, cost=%lld\n", xiangcun, cost);
	if (xiangcun > k) {
//		for (int i = 0; i < depth; ++i) printf("\t");
//		printf("Start Kurskal!\n");
		ll kr = kruskal2();
//		printf("ans=min(%lld, cost=%lld+KRUSKAL_II=%lld)\n", ans, cost, kr);
		ans = min(ans, cost + kr);
		return ;
	}
//	printf("c[%d]=%d\n", xiangcun, c[xiangcun]);
	if (c[xiangcun] != 0) { // 不改造这个乡村 
//		for (int i = 0; i < depth; ++i) printf("\t");
//		printf("Didn't change %d.\n", xiangcun);
//		++depth;
		dfs(xiangcun + 1, cost);
//		printf("Done not changing %d.\n", xiangcun);
//		--depth;
	}
//	for (int i = 0; i < depth; ++i) printf("\t");
//	printf("Changed %d.\n", xiangcun);
	auto tmp = e;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			e[i][j] = min(e[i][j], a[xiangcun][i] + a[xiangcun][j]);
		}
	}
//	cout << "new lingjiebiao:\n";
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (e[i][j] == Inf) printf("Inf\t");
//			else printf("%d\t", e[i][j]);
//		}
//		printf("\n");
//	}
//	++depth;
	dfs(xiangcun + 1, cost + c[xiangcun]); // 改造这个乡村  
	e = tmp; // 回溯 
//	--depth;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i <= n; ++i) {
		e.push_back({Inf});
		for (int j = 0; j <= n; ++j) {
			e[i].push_back(Inf);
//			printf("e[%d][%d]=%d\n", i, j, e[i][j]);
		} 
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
//		add_edge(u, v, w);
//		add_edge(v, u, w);
		edges[i] = {u, v, w};
		e[u][v] = e[v][u] = w;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
//	cout << "lingjiebiao:\n";
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (e[i][j] == Inf) printf("Inf\t");
//			else printf("%d\t", e[i][j]);
//		}
//		printf("\n");
//	}
	// 骗1~4: 16分：最小生成树 
	if (k == 0) {
		sort(edges + 1, edges + m + 1);
		cout << kruskal() << '\n';
		return 0;
	}
	// 骗5~16: 48分：枚举改造之乡村 
	dfs();
	cout << ans << '\n';
	return 0;
}

