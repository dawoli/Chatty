#include <bits/stdc++.h>
using namespace std;

int n, m, x, k = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> x;
	for (int i = 2; i <= n * m; ++i) {
		int t;
		cin >> t;
		if (t > x) ++k;
	}
	int i = k / n, j = k % n;
	if (j == 0) {
		cout << i << ' ' << n << "\n";
	} else if (i & 1) {
		cout << i + 1 << ' ' << n - j + 1 << "\n";
	} else cout << i + 1 << ' ' << j << "\n";
	return 0;
}
