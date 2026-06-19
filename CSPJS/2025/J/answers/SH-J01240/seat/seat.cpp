#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i];
	int my = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int nowx = 1, nowy = 1;
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == my) {
			cout << nowy << " " << nowx << "\n";
			return 0;
		}
		if (nowy % 2 == 1) {
			if (nowx != n) nowx ++;
			else nowy ++;
		} else {
			if (nowx != 1) nowx --;
			else nowy ++;
		}
	}
	cout << m << " " << n << "\n";
	return 0;
}
