#include<iostream>
#include<fstream>
std::ifstream fin("color.in");
std::ofstream fout("color.out");

long long a[2005];
long long dp[2005][2005][2];
long long maxidp[2005][2];
int n;
long long inf = 1e18;

void solve() {
	long long maxi = 0;
	for (int i = 1; i <= n; ++i) {
		fin >> a[i];
		maxi = std::max(maxi,a[i]);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= maxi; ++j) {
			for (int k = 0; k <= 1; ++k) {
				dp[i][j][k] = -inf;
				maxidp[i][k] = 0;
			}
		}
	}
	dp[0][0][0] =0;
	dp[0][0][1] = 0;
	maxidp[0][0] = 0;
	maxidp[0][1] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= maxi; ++j) {
			for (int k = 0; k <= 1; ++k) {
				dp[i][j][k] = dp[i-1][j][k];
				if (a[i] == a[i-1]){
					dp[i][j][k] += a[i];
				}
				if (j == a[i-1]) {
					dp[i][j][k] = std::max(dp[i][j][k], maxidp[i-1][k^1]);
					dp[i][j][k] = std::max(dp[i][j][k], dp[i-1][a[i]][k^1] + a[i]);
				}
				maxidp[i][k] = std::max(maxidp[i][k], dp[i][j][k]);
				ans = std::max(ans, dp[i][j][k]);
			}
		}
	}
	fout << ans<<"\n";
}

long long dp1[200005][15][2];
long long maxidp1[200005][2];

void solve1() {
	long long maxi = 0;
	for (int i = 1; i <= n; ++i) {
		fin >> a[i];
		maxi = std::max(maxi,a[i]);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= maxi; ++j) {
			for (int k = 0; k <= 1; ++k) {
				dp1[i][j][k] = -inf;
				maxidp1[i][k] = 0;
			}
		}
	}
	dp1[0][0][0] =0;
	dp1[0][0][1] = 0;
	maxidp1[0][0] = 0;
	maxidp1[0][1] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= maxi; ++j) {
			for (int k = 0; k <= 1; ++k) {
				dp1[i][j][k] = dp1[i-1][j][k];
				if (a[i] == a[i-1]){
					dp1[i][j][k] += a[i];
				}
				if (j == a[i-1]) {
					dp1[i][j][k] = std::max(dp1[i][j][k], maxidp1[i-1][k^1]);
					dp1[i][j][k] = std::max(dp1[i][j][k], dp1[i-1][a[i]][k^1] + a[i]);
				}
				maxidp1[i][k] = std::max(maxidp1[i][k], dp1[i][j][k]);
				ans = std::max(ans, dp1[i][j][k]);
			}
		}
	}
	fout << ans<<"\n";
}

int main() {
	int t;
	fin >> t;
	while (t --> 0) {
		fin>> n;
		if (n <= 2000)
			solve();
		else 
			solve1();
	}
}
