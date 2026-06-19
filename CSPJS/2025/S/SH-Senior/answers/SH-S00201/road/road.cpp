#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
const int maxm = 1e6+5;
const int maxn = 1e4+30;
struct Edge {
	int u,v,w,nxt;
	int cx; // 哪个村里建的
} edge[maxm * 10];
bool cmp(Edge e1, Edge e2) {
	return e1.w < e2.w;
}
int head[maxn],cnt,fa[maxn];
void init() {
	for (int i = 1; i <= n + k; ++i) fa[i] = i;
}
int find(int u) {
	if (fa[u] != u) fa[u] = find(fa[u]);
	return fa[u];
}
void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}
void add(ll u, ll v, ll w, ll ct) {
	cnt++;
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	edge[cnt].cx = ct;
	head[u] = cnt;
}
ll res;
ll tmpaj[maxn],c[15];
unordered_map<ll, ll> mp;
void kruskal() {
	sort(edge + 1, edge + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; ++i) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		int cx = edge[i].cx;
		if (find(u) != find(v)) {
			if (cx) {
				if (mp[cx] > 0) res -= c[cx];
				mp[cx]++;
			}
			merge(u, v);
			res += w;
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	init();
	for (int i = 1; i <= m; ++i) {
		ll x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		add(x, y, z, 0);
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; ++j) {
			scanf("%lld", &tmpaj[j]);
		}
		for (int j = 1; j <= n; ++j) {
			for (int l = j + 1; l <= n; ++l) {
				if (c[i] == 0) add(j, l, tmpaj[j] + tmpaj[l], 0);
				else add(j, l, c[i] + tmpaj[j] + tmpaj[l], i);
			}
		}
	}
	kruskal();
	printf("%lld", res);
	return 0;
}
