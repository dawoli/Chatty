#include<bits/stdc++.h>
using namespace std;
int t, n, sz, m, tb[23] = {0, -1, 1, 7, 4, 2, 6, 8, 18, 24, 22, 20, 28, 68, 88, 188, 202, 200, 208, 288, 688, 888, 1888};
void solve() {
	cin >> n;
	if (n < 23) cout << tb[n];
	else {
		sz = (n + 6) / 7, m = n % 7;
		if (2 <= m && m <= 5) {
			cout << 2;
			for (int i = m; i < 5; i++) cout << 0;
			for (int i = 7 - m; i <= sz; i++) cout << 8;
		} else if (m == 0)
			for (int i = 1; i <= sz; i++) cout << 8;
		else if (m == 1) {
			cout << 1;
			for (int i = 2; i <= sz; i++) cout << 8;
		} else if (m == 6) {
			cout << 6;
			for (int i = 2; i <= sz; i++) cout << 8;
		}
	}
	cout << endl;
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) solve();
	return 0;
}
