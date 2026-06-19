#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1e4 + 30;
const int M = 2e6 + 10;

struct node {
	int u, v, w;
};

int n, m, k, ans;
node a[M];
int fa[N], v[20];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) fa[x] = y;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
		for (int j = 1; j <= n; j++) {
			a[++m].u = j;
			a[m].v = n + i;
			cin >> a[m].w;
		}
	}
	n += k;
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int xr = find(a[i].u), yr = find(a[i].v);
		if (xr != yr) {
			Union(xr, yr);
			ans += a[i].w;
		}
	} 
	cout << ans << "\n";
	return 0;
}
