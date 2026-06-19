#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 5005;

int n, ans, a[N];

int main () {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (n <= 20) {
		for (int i = 0; i < (1<<n); i++) {
			int sum = 0, mx = 0;

			for (int j = 0; j < 20; j++) {
				if (i & (1<<j)) {
					sum += a[j+1];
					mx = max (mx, a[j+1]);
				}
			}

			if (sum > mx*2) {
				ans = (ans+1) % mod;
			}
		}

		cout << ans%mod;
	}

	return 0;
}
