#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int v, w;
};

struct Stat {
	int u, fa, dist;
	bool operator>(const Stat &stat) {
		return dist > stat.dist;
	}
};

long long ans = INT_MAX;
int N, M, K;
vector<int> C;
vector<bool> Upg;
vector<vector<Edge>> G;
vector<vector<int>> Val;

void test() {
	long long cost = 0;
	vector<vector<Edge>> g(G);
	for(int i = 1; i <= K; i++) {
		if(Upg[i]) {
			cost += C[i];
		}
	}
	vector<int> Fa(N + K + 1);
	priority_queue<Stat, vector<Stat>, greater<>> pq;

	pq.push(Stat{1, 1, 0});
	while(!pq.empty()) {
		Stat x = pq.top(); pq.pop();
		int u = x.u, fa = x.fa, dist = x.dist; 
		if(Fa[u]) {
			continue;
		} Fa[u] = fa;
		cost += dist;
		for(Edge y : g[u]) {
			int v = y.v, w = y.w;
			if(Fa[v]) {
				continue;
			}
			if(v > N && !Upg[v - N]) {
				continue;
			}
			pq.push(Stat{v, u, w});
		}
	}
	ans = min(ans, cost);
}

void dfs(int d) {
	if(d > K) {
		test();
		return;
	}
	Upg[d] = false;
	dfs(d + 1);
	Upg[d] = true;
	dfs(d + 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> N >> M >> K;
	G = vector<vector<Edge>>(N + K + 1);
	for(int i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		G[u].push_back(Edge{v, w});
		G[v].push_back(Edge{u, w});
	}
	C = vector<int>(K + 1);
	Val = vector<vector<int>>(K + 1, vector<int>(N + 1));
	for(int i = 1; i <= K; i++) {
		cin >> C[i];
		for(int j = 1; j <= N; j++) {
			cin >> Val[i][j];
			G[N + i].push_back(Edge{j, Val[i][j]});
			G[j].push_back(Edge{N + i, Val[i][j]});
		}
		
	}
	Upg = vector<bool>(K + 1);
	dfs(1);
	cout << ans << '\n';
	return 0;
} 
