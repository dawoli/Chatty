#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans, c[5005][5005], mx, sum;
bool vis[5005];
void dfs(int step, int sum, int maxn, int c, bool flag) {
	if (c > 2 && sum > 2 * maxn && flag) ans++;
	if (step > n) return;
	dfs(step + 1, sum, maxn, c, 0);
	vis[step] = 1;
	dfs(step + 1, sum + a[step], a[step], c + 1, 1);
	vis[step] = 0;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	c[1][1] = c[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= 998244353;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}
	if (mx == 1) {
		for (int j = n; j > 2; j--) {
			ans += c[n][j];
			ans %= 998244353;
		}
		cout << ans <<'\n';
		return 0;
	}
	sort(a + 1, a + 1 + n);
	dfs(1, 0, 0, 0, 0);
	cout << ans << '\n';
	return 0;
}
/*
25
*/ 
