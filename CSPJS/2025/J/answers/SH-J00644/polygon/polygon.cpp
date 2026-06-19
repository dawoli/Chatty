#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[8196];
void dfs(int idx, int x, int m, int sum) {
	if (x >= 3)
		if (sum > 2 * m)
			ans++;
	ans %= 998244353;
	for (int i = idx + 1; i <= n; i++)
		dfs(i, x + 1, max(m, a[i]), sum + a[i]);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 2; i ++)
		dfs(i, 1, a[i], a[i]);
	cout << ans;
	return 0;
}
