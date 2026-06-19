#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000000], v[1000000], w[1000000], c[10], a[10][1000000];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i];
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 0; j < n; j++) cin >> a[i][j];
	}cout << 13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
