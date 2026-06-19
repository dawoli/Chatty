#include <bits/stdc++.h>
using namespace std;

const int V = 1e6 + 1e5 + 10;
const int N = 5e5 + 10;
int n, k, a[N], pos[V];
int dp[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	memset(pos, -1, sizeof(pos));
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i]; a[i] ^= a[i - 1];
	}
	pos[0] = 0;
	for (int i = 1; i <= n; i ++) {
		dp[i] = dp[i - 1];
		if (pos[a[i] ^ k] != -1)
			dp[i] = max(dp[i], dp[pos[a[i] ^ k]] + 1);
		pos[a[i]] = i;
	}
	cout << dp[n] << "\n";
	return 0;
}
