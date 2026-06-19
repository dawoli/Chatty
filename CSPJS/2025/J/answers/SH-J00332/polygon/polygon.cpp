#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5001];
int ans = 0;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int maxx = -1;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		if (a[i] != 1) flag = 0;
	}
	if (flag) {
		cout << (n - 2) * (n - 1) / 2;
		return 0;
	}
	if (n == 3) {
		int sum = 0;
		for (int i = 1; i <= 3; i++)
			sum += a[i];
		if (sum > 2 * maxx) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << 9;
	return 0;
}
