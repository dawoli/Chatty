#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005], xq;
int p[11][11];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	xq = a[1];
	sort(a + 1, a + n * m + 1);
	int x = 1, y = 1;
	for(int i = n * m; i >= 1; --i) {
		p[x][y] = a[i];
		if(y % 2 == 1) {
			++x;
			if(x == n + 1) {
				++y; --x;
			}
		}
		else {
			--x;
			if(x == 0) {
				++y; ++x;
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(p[i][j] == xq) {
				cout << j << " " << i << endl;
			}
		}
	}
	return 0;
}