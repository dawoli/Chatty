#include<bits/stdc++.h>
using namespace std;
int n, m, r, a;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	int rst = n * m - 1;
	int x = 1, y = 1, d = 1;
	for (int i = 1; i <= rst; i++) {
		cin >> a;
		if (a < r) continue;
		x += d;
		if (x > n || !x) d = -d, x += d, y++;
	}
	cout << y << ' ' << x;
	return 0;
}
