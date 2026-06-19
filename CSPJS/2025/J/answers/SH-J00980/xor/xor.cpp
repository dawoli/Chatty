#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], pfxor[500005], lsxor[2000005], dp[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		pfxor[i] = (pfxor[i - 1] ^ a[i]);
	}
	for(int i = 1; i <= 2000000; ++i) lsxor[i] = -1;
	for(int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if(lsxor[pfxor[i] ^ k] >= 0) {
			dp[i] = max(dp[i], dp[lsxor[pfxor[i] ^ k]] + 1);
		}
		lsxor[pfxor[i]] = i;
	}
	cout << dp[n] << endl;
	return 0;
}