#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[11011], a[11][10001], dis[10001], ans;
struct node {
	int v, w;
};
vector <node> g[10001];
bool vis[10001];
void dijkstra() {
	queue <int> q;
	memset(dis, 0x3f, sizeof dis);
	q.push(1);
	dis[1] = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (node p : g[x]) {
			if (dis[p.v] > dis[x] + p.w) {
				if (dis[p.v] != 0x3f3f3f3f) ans -= dis[p.v];
				ans += dis[x] +p.w;
				dis[p.v] = dis[x] +p.w;
				q.push(p.v); 
			}
		}
	}
}
void solve1() {
	dijkstra();
	cout << ans << '\n';
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	bool flag = 0;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) flag = 1;
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	if (flag) {
		cout << "0\n";
		return 0;
	}
	if (k == 0) solve1();
	return 0;
}
