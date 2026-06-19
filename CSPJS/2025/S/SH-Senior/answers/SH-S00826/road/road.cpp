#include <iostream>
#include <algorithm>
using namespace std;
constexpr long long INF = 1.1e15 + 5;
struct edge {
	int u, v, w;
	bool operator<(edge other) {
		return w < other.w;
	}
	void read() {
		cin >> u >> v >> w;
	}
};
int n, m, k, u, v, w, c[15], a;
edge edges[1100005];
bool flag[15];
int len, f[10015], cnt;
long long sum, ans = INF;
int rt(int idx) {
	if (f[idx] == idx) return idx;
	else return f[idx] = rt(f[idx]);
}
void update() {
	for (int i = 1; i <= n + k; ++i)
		f[i] = i;
	cnt = n;
	sum = 0;
	for (int i = 1; i <= k; ++i) {
		if (!flag[i]) continue;
		++cnt;
		sum += c[i];
	}
	int cur = 1;
	for (int i = 1; cur < cnt; ++i) {
		if (edges[i].u > n && 
			!flag[edges[i].u - n])
			continue;
		const int rtu = rt(edges[i].u);
		const int rtv = rt(edges[i].v);
		if (rtu == rtv) continue;
		sum += edges[i].w;
		f[rtu] = rtv;
		++cur;
	}
	ans = min(ans, sum);
}
void dfs(int idx) {
	if (idx == k + 1) {
		update();
		return;
	}
	flag[idx] = false;
	dfs(idx + 1);
	flag[idx] = true;
	dfs(idx + 1);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		edges[++len].read();
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a;
			edges[++len] = { n + i, j, a };
		}
	}
	sort(edges + 1, edges + len + 1);
	dfs(1);
	cout << ans;
	return 0;
}
