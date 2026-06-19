#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[5005];

void dfs(int i, int m, int cnt, int mx) {
	if (i > n) {
		if (m >= 3 && cnt > 2 * mx) {
			ans++;
		}
//		cout << cnt << " " << mx << "\n";
		ans %= 998244353;
		return;
	}
	dfs(i + 1, m, cnt, mx);
	dfs(i + 1, m + 1, cnt + a[i], max(mx, a[i]));
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0, -1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

