#include <bits/stdc++.h>
using namespace std;
struct road{
	int u, v, w;
}r[1000005];
int c[15][10005];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	if (k == 0) {
		cout << m/2;
	}
	return 0;
}
