#include<iostream>
using namespace std;

int n, m, k, u, v, w, ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		ans += w;
	}
	cout << ans;
	
	return 0;
}
