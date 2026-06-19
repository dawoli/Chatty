#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 1e6, mod = 998244353;
int n, m, c[N], dp[M][25];
char s[N];

int cnt(int x) {
	int res = 0;
	while (x)
		res += x & 1, x >>= 1;
	return res;
}

int jc(int x) {
	int res = 1;
	for (int i = 1; i <= x; i++)
		res = res * i % mod;
	return res; 
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		scanf("%lld", c + i);
	int S = 1ll << n;
	dp[0][0] = 1;
	for (int i = 1; i < S; i++) {
		int l = cnt(i);
		for (int j = 0; j <= l; j++) {
			for (int k = 1; k <= n; k++) {
				if (!((1ll << (k - 1)) & i))
					continue;
				if (s[l] == '1' && c[k] > l - j)
					(dp[i][j] += dp[i ^ (1ll << (k - 1))][j - 1]) %= mod;
				if (s[l] == '0' || c[k] <= (l - 1 - j))
					(dp[i][j] += dp[i ^ (1ll << (k - 1))][j]) %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = m; i <= n; i++)
		ans += dp[S - 1][i];
	cout << ans % mod;
	return 0;
}

