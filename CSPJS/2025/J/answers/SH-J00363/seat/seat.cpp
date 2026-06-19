#include <bits/stdc++.h>
using namespace std;

int a[180], b[15][15];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
	}
	int R = a[1];
	sort(a+1, a+n*m+1, cmp);
	int x = 1, y = 1, d = 1, cnt = 1;
	while (cnt <= n*m) {
		b[x][y] = a[cnt++];
		if (d == 1) {
			if (x == n) {
				d = 2;
				y++;
			} else {
				x++;
			}
		} else {
			if (x == 1) {
				d = 1;
				y++;
			} else {
				x--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == R) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}
