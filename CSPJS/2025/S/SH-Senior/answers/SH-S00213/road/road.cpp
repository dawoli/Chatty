#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
	}
	cout << ans << endl;
	return 0;
}
