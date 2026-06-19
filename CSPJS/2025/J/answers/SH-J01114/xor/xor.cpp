#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], wz = 1, ans;
long long sum[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] xor a[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == k) {
			ans++, wz = i + 1;
			continue;
		}
		for (int j = wz; j < i; ++j) {
			long long x = sum[i] xor sum[j - 1];
			if (x == k) {
				ans++, wz = i + 1;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

