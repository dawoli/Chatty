#include <bits/stdc++.h>
using namespace std;
const int c = 998244353;
int n, ans, a[5005], b[5005];
int sum(int end) {
	int s = 0;
	for (int i = 1; i <= end; i++) s += b[i];
	return s;
}
void dfs(int d, int pre) {
	if (d >= 4) {
		if (sum(d-1) > 2 * b[d-1]) {
			ans = (ans + 1) % c;
		}
	}
	for (int i = pre + 1; i <= n; i++) {
		b[d] = a[i];
		dfs(d+1, i);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (a[n] == 1) {
		cout << (((1 << n) - 1 - n - n * (n-1) / 2) % c + c) % c;
		return 0;
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
