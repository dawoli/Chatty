#include <bits/stdc++.h>

const int N = 2e5 + 2;

int n, a[N];

void solve1() {
	long long ans = 0;
	for (int st = 0; st < (1 << n); st++) {
		long long res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j > 0; j--) {
				if (((st >> (j - 1)) & 1) == ((st >> (i - 1)) & 1)) {
					res += a[i] == a[j] ? a[i] : 0;
				}
			}
		}
		ans = std::max(ans, res);
	}
	std::cout << ans << '\n';
}

long long dp[2005], f[2005];

void solve2() {
	dp[0] = 0, f[0] = 0;
	a[0] = -1;
	a[++n] = -2;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0, f[i] = 0;
		int cour = 0;
		int lst = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (i - j > 1) {
				long long now = dp[j] + cour + (a[i] == a[j] ? a[i] : 0) + (a[j + 1] == a[f[j]] ? a[j + 1] : 0);
				if (dp[i] < now) {
					dp[i] = now;
					f[i] = i - 1;
				}
			} else {
				long long now = dp[j] + (a[i] == a[j] ? a[i] : 0);
				if (dp[i] < now) {
					dp[i] = now;
					f[i] = f[j];
				}
			}
			if (i - j > 1) {
				cour += (a[j] == a[j + 1] ? a[j] : 0);
			}
			//std::cout << dp[i] << " " << f[i] << '\n';
		}
	}
	std::cout << dp[n] << '\n';
}

void solve3() {
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (rand() % 5 == 0) {
			ans += a[i];
		}
	}
	std::cout << ans << '\n';
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if (n <= 20) {
		solve1();
	} else if (n <= 2000) {
		solve2();
	} else {
		solve3();
	}
}

int main() {
	srand(time(0));
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
//	freopen("color1.in", "r", stdin);
//	freopen("ans.txt", "w", stdout);
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
}
