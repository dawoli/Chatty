#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) cin >> a[i];
	int s = a[0];
	sort(a, a + n*m, cmp);
	int c = 1, r = 1;
	for (int i = 0; i < n * m; i++) {
		if (a[i] == s) {
			cout << c << " " << r;
			return 0;
		}
		if (c % 2 == 1) {
			if (r == n) c++;
			else r++;
		} else {
			if (r == 1) c++;
			else r--;
		}
	}
	return 0;
}
