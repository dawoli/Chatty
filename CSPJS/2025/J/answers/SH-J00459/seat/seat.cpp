#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int nm = n * m - 1;
	int xr;
	cin >> xr;
	for (int i = 0; i < nm; i++)
		cin >> a[i];
	sort(a, a + nm, greater<int>());
	int id = -1;
	for (int i = 0; i < nm; i++)
		if (xr > a[i]) {
			id = i + 1;
			break;
		}
	if (id == -1) id = nm + 1;
	bool down = true;
	int curr = 0;
	for (int c = 1; c <= m; c++) {
		if (down) for (int r = 1; r <= n; r++) {
			curr++;
			if (curr == id) {
				cout << c << ' ' << r;
				return 0;
			}
		}
		else for (int r = n; r >= 1; r--) {
			curr++;
			if (curr == id) {
				cout << c << ' ' << r;
				return 0;
			}
		}
		down = !down;
	}
	return 0;
}
