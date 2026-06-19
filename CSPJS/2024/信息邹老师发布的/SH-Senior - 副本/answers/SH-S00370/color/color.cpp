#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int T, n, a[N], dp[N][2][N];

inline void Max(int& x, int y) {
	x = max(x, y);
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 1; k < i; k++)
					dp[i][j][k] = 0;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 1; k <= i - 1; k++)
					Max(dp[i + 1][j][k], dp[i][j][k] + (a[i] == a[i + 1] ? a[i] : 0)), Max(dp[i + 1][!j][i], dp[i][j][k] + (a[i + 1] == a[k] ? a[k] : 0));
		int ans = 0;
		for (int j = 0; j < 2; j++)
			for (int k = 1; k < n; k++)
				Max(ans, dp[n][j][k]);
		cout << ans << "\n";
	}
	return 0;
}

