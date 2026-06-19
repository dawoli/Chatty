#include <bits/stdc++.h>
#define int long long
#define maxn 100010
using namespace std;

int n, m, c, r, point, mark, a[maxn], t[maxn];
void solve() {
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m - 1; i++) {
		if (mark > a[i]) {
			point = i;
			memset(t, 0, sizeof(t));
			for (int j = i; j <= n * m - 1; j++) {
				t[j] = a[j];
			}
			a[i] = mark;
			for (int j = i + 1; j <= n * m; j++) {
				a[j] = t[j - 1];
			}
			break;
		}
	}
	if (((point - point % n) / m + 1) % 2 == 0) {
		r = point - (point - n * (point / n));
	}
	else {
		if (point % n == 0) {
			r = n;
		}
		else {
			r = point % n;
		}
	}
	if (point % n == 0) {
		c = point / n;
	}
	else {
		c = (point - point % n) / n + 1;
	}
	cout << c << " " << r << endl;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	m = n = 1;
	cin >> n >> m >> mark;
	for (int i = 1; i <= n * m - 1; i++) {
		cin >> a[i];
	}
	solve();
	return 0;
}

