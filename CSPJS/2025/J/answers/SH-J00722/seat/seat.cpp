#include <iostream>
#include <cstdio>
using namespace std;

int n, m, a, t, c, r, pos = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a;
	for (int i = 1; i < n * m; i++) {
		cin >> t;
		if (t > a) {
			pos++;
		}
	}
	c = pos / n + 1;
	if (pos % n == 0) {
		c--;
	}
	if (c % 2 == 0) {
		r = n - pos % n + 1;
		if (pos % n == 0) {
			r = 1;
		}
	} else {
		r = pos % n;
		if (pos % n == 0) {
			r = n;
		}
	}
	cout << c << ' ' << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
