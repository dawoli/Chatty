#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
struct Edge {
	int start;
	int dest;
	int v1;
	int v2;
	bool operator < (const Edge &other) const {
		return v1 + v2 > other.v1 + other.v2;
	}
};
priority_queue<Edge> pq;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	vector<Edge> edges[n + k];
	bool visited[n + k] = {};
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		edges[u].push_back({u, v, w, 0});
		edges[v].push_back({v, u, w, 0});
	}
	for (int i = n; i < n + k; ++i) {
		int c;
		cin >> c;
		for (int j = 0; j < n; ++j) {
			int w;
			cin >> w;
			edges[i].push_back({i, j, w, 0});
			edges[j].push_back({j, i, w, c});
		}
	}
	int sum = 0, visited_cities = 0;
	visited[0] = true;
	visited_cities++;
	for (int i = 0; i < edges[0].size(); ++i) pq.push(edges[0][i]);
	while (!pq.empty()) {
		const Edge edge = pq.top();
		pq.pop();
		if (visited[edge.dest]) continue;
		sum += (edge.v1 + edge.v2);
		visited[edge.dest] = true;
		if (edge.dest < n) visited_cities++;
		if (visited_cities == n) break;
		for (int i = 0; i < edges[edge.dest].size(); ++i) pq.push(edges[edge.dest][i]);
	}
	cout << sum << endl;
	return 0;
}
