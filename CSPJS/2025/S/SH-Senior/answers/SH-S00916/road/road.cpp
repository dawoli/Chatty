#include <bits/stdc++.h>
using namespace std;
struct Line {
	int e1, int e2, int price;
} a[1000010];
int n, m, k, vil[15][10010], stat_c[10010], stat_v[15], ans;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i)	cin >> a[i].e1 >> a[i].e2 >> a[i].price;
	for(int i = 1; i <= k; ++i) {
		cin >> vil[i][0];
		for(int j = 1; j <= n; ++j) cin >> vil[i][j];
	}
	return 0;
}
