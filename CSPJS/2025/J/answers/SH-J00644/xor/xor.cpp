#include <bits/stdc++.h>
using namespace std;
int n, k, a[int(1e5 * 5)], x, ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		x ^= a[i];
		if (x == k) {
			x = 0;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
