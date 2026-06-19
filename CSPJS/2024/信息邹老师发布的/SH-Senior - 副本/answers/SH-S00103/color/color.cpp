#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
using std::cin; using std::cout; using std::max;
const int maxN = 200007;

inline void gma(int &x, int y) {
	if (x < y)
		x = y;
}

namespace A {
	const int maxN = 2007;
	int dp[maxN][maxN], a[maxN];
	void solve(int n) {
		rep(i, 1, n)
			cin >> a[i];
		rep(i, 1, n)
			rep(j, 0, 2000)
				dp[i][j] = -0x3f3f3f3f;
		dp[1][0] = 0;
		rep(i, 1, n - 1)
			rep(j, 0, 2000) {
				if (a[i] == a[i+1])
					gma(dp[i+1][j], dp[i][j] + a[i]);
				else
					gma(dp[i+1][j], dp[i][j]);
				if (j == a[i+1])
					gma(dp[i+1][a[i]], dp[i][j] + j);
				else
					gma(dp[i+1][a[i]], dp[i][j]);
			}
		int ans = 0;
		rep(j, 0, 2000)
			gma(ans, dp[n][j]);
		cout << ans << "\n";
	}
}
namespace B {
	const int maxN = 200007;
	int dp[maxN][17], a[maxN];
	void solve(int n) {
		rep(i, 1, n)
			cin >> a[i];
		rep(i, 1, n)
			if (a[i] > 10) {
				cout << "0\n";
				return;
			}
		rep(i, 1, n)
			rep(j, 0, 10)
				dp[i][j] = -0x3f3f3f3f;
		dp[1][0] = 0;
		rep(i, 1, n - 1)
			rep(j, 0, 10) {
				if (a[i] == a[i+1])
					gma(dp[i+1][j], dp[i][j] + a[i]);
				else
					gma(dp[i+1][j], dp[i][j]);
				if (j == a[i+1])
					gma(dp[i+1][a[i]], dp[i][j] + j);
				else
					gma(dp[i+1][a[i]], dp[i][j]);
			}
		int ans = 0;
		rep(j, 0, 10)
			gma(ans, dp[n][j]);
		cout << ans << "\n";
	}
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n <= 2000)
			A::solve(n);
		else
			B::solve(n);
	}
	return 0;
}
