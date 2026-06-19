#include<bits/stdc++.h>
using namespace std;
const int N = 500009, A = 1100009;
int rcd[A], a[N], dp[N], n, k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
	fill(rcd + 1, rcd + A, -1);
	for (int i = 1; i <= n; i++) {
		if (rcd[a[i] ^ k] == -1) dp[i] = dp[i - 1];
		else dp[i] = max(dp[i - 1], dp[rcd[a[i] ^ k]] + 1);
		rcd[a[i]] = i;
	}
	cout << dp[n];
	return 0;
}
