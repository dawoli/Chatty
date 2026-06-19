#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, m, a[10] = {0}, cnt = 0, ans = 0;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 8; j++) {
				string s;
				cin >> s;
				a[i] += (s == "math");
			}
			cnt += a[i];
		}
		cin >> n >> m;
		ans += n / 7 * cnt;
		n %= 7;
		while (n) {
			ans += a[m++], n--;
			if (m == 8) m = 1;
		}
		cout << ans << endl;
	}
	return 0;
}
