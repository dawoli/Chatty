#include <bits/stdc++.h>
using namespace std;
const int stck[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int T, n; 
signed main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		int len = (n + 6) / 7;
		for (int i = 1; i <= len; ++i) {
			for (int j = (i == 1); j <= 9; ++j) {
				int nxtN = n - stck[j];
				if ((nxtN > 1 || nxtN == 0) && nxtN <= (len - i) * 7) {
					n = nxtN;
					cout << j;
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
