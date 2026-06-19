#include <bits/stdc++.h>

using namespace std;
const int N = 200010;

int t;

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n, a[N], st[N];
		long long ans = 0; 
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i < 1 << n; i++) {
			long long sum = 0;
			for (int j = 0; j < n; j++) {
				st[j] = i >> j & 1;
			}
			for (int i = 2; i <= n; i++) {
				for (int j = i - 1; j >= 1; j--) {
					if (st[j] == st[i]) {
						if (a[j] == a[i]) sum += a[i];
					}
				}
			}
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}
	return 0;
} 
