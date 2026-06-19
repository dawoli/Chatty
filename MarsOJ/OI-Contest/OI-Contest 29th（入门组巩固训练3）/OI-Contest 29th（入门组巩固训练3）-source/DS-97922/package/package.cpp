#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt, v[10005];
struct node {
	int t, w;
} a[10005];
int main() {
	freopen("package.in", "r", stdin);
	freopen("package.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) cin >> a[i].t >> a[i].w;
	if (n == 1) {
		cout << v[a[i].w] << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) cnt += a[i].w;
	cout << cnt << endl;
	return 0;
}
