#include <bits/stdc++.h>
using namespace std;

int a[110] = {};

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	int r, R = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == R) {
			r = i;
		}
	}
	r = n * m - r + 1;
	int c = r / n + 1, h;
	if (r % n == 0) {
		c --;
	}
	h = r % n;
	if (h == 0) {
		h = n;
	}
	if (c % 2 == 0) {
		h = n - h + 1;
	}
	cout << c << " " << h;
	return 0;
}
