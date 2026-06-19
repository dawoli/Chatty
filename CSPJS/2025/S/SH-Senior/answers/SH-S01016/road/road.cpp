#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 1e4+10, M = 1e6+10;
typedef long long ll;

struct Edge {
	int beg, end;
	ll cost;
};
int n, m, k, change[15], father[N];
vector<Edge>G;
bool f[15];
ll ans, res = 1e16;

void init() {
	for (int i = 1; i <= n+k+10; i ++) {
		father[i] = i; 
	}
}

bool cmp(Edge x, Edge y) {
	return x.cost<y.cost;
}

int find(int x) {
	if (father[x]==x) return x;
	return father[x] = find(father[x]);
}

void manage(int x, int y, ll cos) {
	int fx = find(x), fy = find(y);
	if (fx==fy) return;
	father[fx] = fy;
	ans += cos;
	return;
}

void bfs() {
	init(); 
	for (int i = 0; i < G.size(); i ++) {
		if (G[i].beg>n&&f[G[i].beg-n]==0||G[i].end>n&&f[G[i].end-n]==0) continue;
		manage(G[i].beg, G[i].end, G[i].cost);
	}
	res = min(res, ans);
	return;
}

void dfs(int pos) {
	if (pos==k+1) {
		int ans2 = ans;
		bfs();
		ans = ans2;
		return;
	}
	f[pos] = 1;
	ans += change[pos];
	dfs(pos+1);
	ans -= change[pos];
	f[pos] = 0;
	dfs(pos+1);
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	cin>>n>>m>>k;
	for (int i = 1; i <= m; i ++) {
		int beg, end, cost;
		cin>>beg>>end>>cost;
		G.push_back({end, beg, cost});
	}
	for (int i = 1; i <= k; i ++) {
		cin>>change[i];
		for (int j = 1; j <= n; j ++) {
			int cost;
			cin>>cost;
			G.push_back({j, i+n, cost});
		}
	}
	sort(G.begin(), G.end()-1, cmp);
	dfs(1);
	cout<<res;
	return 0;
}
