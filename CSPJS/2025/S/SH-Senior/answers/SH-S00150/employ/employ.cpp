#include <bits/stdc++.h>

using namespace std;

const int N = 511, p = 998244353, M = 18;
int n, m, c[N], dp[M + 1][(1 << M) + 1][M + 1];
char s[N];

inline void dfs(int i, int x, int t, int num) {
	if (t - x > n - i)
		return;
	if (i == n) {
		for (int j = 0; j < t; j++)
			for (int k = 0; k < n; k++)
				if (num & (1 << k)) {
					if (j >= c[k + 1] || s[t] == '0') {
						dp[t][num][j + 1] += dp[t - 1][num - (1 << k)][j];
						dp[t][num][j + 1] %= p;
					} else {
						dp[t][num][j] += dp[t - 1][num - (1 << k)][j];
						dp[t][num][j] %= p;
					}
				}
		return;
	}
	dfs(i + 1, x, t, num);
	if (x < t)
		dfs(i + 1, x + 1, t, num + (1 << i));
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
		dfs(0, 0, i, 0);
	int ans = 0;
	for (int i = 0; i <= n - m; i++)
		ans += dp[n][(1 << n) - 1][i], ans %= p;
	printf("%d\n", ans);
	return 0;
}
