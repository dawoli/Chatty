#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > edges[1000005];
void add_edge(int u, int v, int w) {
	edges[u].push_back({v, w});
	edges[v].push_back({u, w});
	cout << "finished\n";
}

void solveBF(){
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
	}
	dfs(1, 0, 0);
	printf("%lld", ans);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	if (k == 0) solveBF();
	return 0;
}
