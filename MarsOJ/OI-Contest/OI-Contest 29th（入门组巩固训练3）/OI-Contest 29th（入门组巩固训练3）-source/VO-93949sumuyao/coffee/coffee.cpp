#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int A[8] = {0}, sum = 0;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 8; j++) {
				string s;
				cin >> s;
				if (s == "math") {
					A[i]++;
					sum++;
				}
			}
		}
		ll m, n, ans = 0;
		cin >> m >> n;
		while (m && n != 1) {
			ans += A[n];
			m--;
			n++;
			if (n == 8) n = 1;
		}
		ans += m / 7 * sum;
		m -= m / 7 * 7;
		while (m) {
			ans += A[n];
			m--;
			n++;
			if (n == 8) n = 1;
		}
		cout << ans << endl;
	}
	return 0;
}
 
