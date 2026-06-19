#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int n, m, e, pos, l, r, col, row;
int a[maxn];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	e = a[1];
	l = 1;
	r = n * m;
	sort(a + 1, a + n * m + 1, greater<int>());
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] < e) {
			r = mid - 1;
		} else if (a[mid] > e) {
			l = mid + 1;
		} else {
			pos = mid;
			break;
		}
	}
	col = (pos - 1) / n + 1;
	row = abs((col % 2 ? 0 : n + 1) - 1 - ((pos - 1) % n));
	cout << col << " " << row;
	return 0;
}
