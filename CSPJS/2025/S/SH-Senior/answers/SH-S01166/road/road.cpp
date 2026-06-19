#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

int n, m, k;
int c[15];

struct edge {
	int dest, len;
};

inline bool operator< (const edge x, const edge y) {
	return x.len > y.len;
}

struct adjacencyList {
	std::vector <edge> content[10015];

	void insert(int x, int y, int len) {
		content[x].push_back({y, len});
		content[y].push_back({x, len});
	}
};

struct undirectedGraph : adjacencyList {
	int d[10015], size;
	long long ans;
	bool vis[10015];

	void prim() {
		ans = 0;
		for (int i = 1; i <= size; i++) d[i] = 0x3fffffff;
		std::priority_queue <edge> next; next.push({1, 0});
		while (next.size()) {
			int cur = next.top().dest, delta = next.top().len; next.pop();
			if (vis[cur]) continue;
			vis[cur] = true, ans += delta;
			for (edge nxt : content[cur]) {
				int dest = nxt.dest, len = nxt.len;
				if (!vis[dest] && len < d[dest]) d[dest] = len, next.push({dest, len});
			}
		}
	}
}base;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::cin>>n>>m>>k; base.size = n + k;
	for (int i = 1; i <= m; i++) {
		int x, y, len; std::cin>>x>>y>>len;
		base.insert(x, y, len);
	}
	bool flag = true;
	for (int i = 1; i <= k; i++) {
		std::cin>>c[i]; if (c[i] > 0) flag = false;
		for (int j = 1; j <= n; j++) {
			int len; std::cin>>len;
			base.insert(n + i, j, len);
		}
	}

	if (flag) {
		base.prim();
		std::cout<<base.ans<<"\n";
		return 0;
	}

	long long ans = 0x3fffffffffffffff;
	for (int i = 0; i < (1 << k); i++) {
		long long res = 0;
		for (int j = 1; j <= n + k; j++) base.vis[j] = false;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) res += c[j + 1];
			else base.vis[n + j + 1] = true;
		}
		base.prim();
		ans = std::min(ans, res + base.ans);
	}

	std::cout<<ans<<"\n";
	return 0;
}
