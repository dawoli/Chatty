#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, M = 1e4 + 9;

struct node {
	int v, w;
};
int n, m, k, dfn[N], low[N], idx, ins[N], bl, id[N], ans, p[N];
stack <int> s;
vector <node> e[N];
int a[M][M], block[N], num[N];

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++idx;
	ins[u] = 1;
	s.push(u);
	for(int i = 0; i < e[u].size(); i ++) {
		int v = e[u][i].v;
		if(v == fa) continue;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if(ins[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	
	if(low[u] == dfn[u]) {
		bl ++;
		while(s.size()) {
			int v = s.top(); s.pop();
			ins[v] = 0;
			id[v] = bl;
			block[bl] ++;
			if(u == v) break;
		}
	}
}		

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while(m --) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		ans += w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i ++) {
		for(int i = 1; i <= n + 1; i ++) {
			cin >> p[i];
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(!dfn[i]) tarjan(i, 0);
	}
	
	for(int u = 1; u <= n; u ++) {
		for(int i = 0; i < e[u].size(); i ++) {
			int v = e[u][i].v;
			if(u < v && id[u] == id[v]) a[id[u]][++num[id[u]]] = e[u][i].w;
		}
	}
	
	for(int i = 1; i <= bl; i ++) {
		sort(a[i] + 1, a[i] + 1 + num[i]);
		for(int j = block[i]; j <= num[i]; j ++) {
			//cout << a[i][j] << '\n';
			ans -= a[i][j];
		}
	}
	cout << ans << '\n';	
	return 0;
}
