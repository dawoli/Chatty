#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
int n, m, k;
ll c[1000006], ans;
int f[1000006];

struct node {int v; ll w;};

struct edge {
	int u, v; ll w;
}E[1000006];

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

vector<node> g[1000006];

struct NODE {
	ll v;
	int id;
}minn[10004];

int find(int p) {
	return p == f[p] ? p : find(f[p]);
}

void conn(int u, int v) {
	f[find(u)] = find(v);
}

bool isconn(int u, int v) {
	return find(u) == find(v);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	memset(minn, 0x3f, sizeof minn);
	for (int i = 1; i <= m; i++) {
		int u, v; ll w;
		scanf("%d%d%lld", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		E[i] = edge{u, v, w};
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	if (k == 0) {
		sort(E + 1, E + m + 1, cmp);
		ll ans = 0;
		for (int i = 1; i < n; i++) {
			if (!isconn(E[i].u, E[i].v)) {
				ans += E[i].w;
				conn(E[i].u, E[i].v);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
