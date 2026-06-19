#include <bits/stdc++.h>
using namespace std;
int n, m, a [110];
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a [i];
	int cur = a [1];
	sort (a + 1, a + n * m + 1, greater <int> ());
	int x = 1, y = 1, cnt = 1;
	for (int i = 1; i <= n * m; i ++) {
		if (a [i] == cur) break;
		if (x == n && cnt == 1) {
			y ++; cnt = -1;
		} else if (x == 1 && cnt == -1) {
			y ++; cnt = 1;
		} else x += cnt;
	}
	cout << y << " " << x;
}