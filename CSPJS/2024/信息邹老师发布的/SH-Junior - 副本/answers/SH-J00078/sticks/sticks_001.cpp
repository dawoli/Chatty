#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int t, a[N] = {34211, 34211, 1, 7, 4, 2, 6, 8}, p[N] = {2, 5, 4, 6, 3, 7};

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << -1 << endl;
		else if (n == 2) cout << 1 << endl;
		else if (n == 3) cout << 7 << endl;
		else if (n == 4) cout << 4 << endl;
		else if (n == 5) cout << 2 << endl;
		else if (n == 6) cout << 6 << endl;
		else if (n % 7 == 0) {
			for (int i = 1; i <= n / 7; i++) cout << 8;
			cout << endl;
		} else if (n % 7 == 1) {
			cout << 1;
			for (int i = 1; i < n / 7; i++) cout << 8;
			cout << 0 << endl; 
		} else {
			int cnt = (n + 6) / 7, ans[N];
			for (int i = 2; i < cnt; i++) ans[i] = 0;
			n -= (cnt - 2) * 6;
			for (int i = 0; i < 6; i++) {
				int j = a[p[i]];
				if (n - p[i] >= 2 && n - p[i] <= 7) {
					ans[1] = j;
					if (n - p[i] != 6) ans[cnt] = a[n - p[i]];
					else ans[cnt] = 0;
					break;
				}
			}
			for (int i = 1; i <= cnt; i++) cout << ans[i];
			cout << endl;
		}
	}
	return 0;
} 
