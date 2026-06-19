#include<bits/stdc++.h>
using namespace std;
int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, t, n, ans, re[20] = {-1, 1, 7, 4, 2, 6, 8, 10, 34, 23, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i ++) {
		cin >> n;
		ans = 0;
		if (n <= 1) {
			cout << -1 << endl;
			continue;
		}
		if (n % 7 == 0) {
			for (int j = 1; j <= n / 7; j ++) {
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if (n % 7 == 1) {
			cout << 10;
			for (int j = 1; j <= n / 7 - 1; j ++) cout << 8;
			cout << endl;
			continue;
		}
		for (int j = 0; j < 20; j ++) {
			if (n == j + 1) cout << re[j] << endl;
		}
	}
	return 0;
}
