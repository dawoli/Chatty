#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
int n;
int a[20];
int co[20];
int dp[110][110][110];//tot red blue
int ycl[110][110];
void dfs(int dep) {
	if(dep == n + 1) {
		int cnt = 0;
		int lastred = 0, lastblue = 0;
		for(int i = 1; i <= n; i++) {
			if(co[i] == 1) {
				if(lastred != 0) {
					if(a[i] == a[lastred]) {
						cnt += a[i];
					}
				}
				lastred = i;
			}
			else {
				if(lastblue != 0) {
					if(a[i] == a[lastblue]) {
						cnt += a[i];
					}
				}
				lastblue = i;
			}
		}
		ans = max(ans, cnt);
		return;
	}
	co[dep] = 1;
	dfs(dep + 1);
	co[dep] = 2;
	dfs(dep + 1);
	co[dep] = 0;
}
void solve() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= n; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		int c = 0;
		for(int j = i + 1; j <= n; j++) {
			if(a[j] == a[j - 1]) {
				c += a[j];
			}
			ycl[i][j] = c;
		}
	}
	for(int i = 1; i <= n; i++) {
		//red
		for(int j = 1; j < i; j++) {
			if(a[i] != a[j]) {
				continue;
			}
			for(int k = 0; k < j; k++) {
				dp[i][i][i - 1] = max(dp[i][i][i - 1], dp[j][j][k] + a[i] + ycl[j + 1][i - 1] + (a[j + 1] == a[k] ? a[k] : 0));
				//printf("%lld %lld %lld %lld %lld %lld %lld\n", i, dp[i][i][i - 1], dp[j][j][k], a[i], ycl[j + 1][i - 1], (a[j + 1] == a[k] ? a[k] : 0), dp[j][j][k] + a[i] + ycl[j + 1][i - 1] + (a[j + 1] == a[k] ? a[k] : 0));
			}
		}
		for(int j = 1; j < i; j++) {
			for(int k = 0; k < j; k++) {
				dp[i][i][i - 1] = max(dp[i][i][i - 1], max(dp[j][j][k] + ycl[j + 1][i - 1] + (a[j + 1] == a[k] ? a[k] : 0), dp[j][k][j] + ycl[j + 1][i - 1]));
				//printf("%lld %lld\n", i, dp[i][i][i - 1]);
			}
		}
		//blue
		for(int j = 1; j < i; j++) {
			if(a[i] != a[j]) {
				continue;
			}
			for(int k = 0; k < j; k++) {
				dp[i][i - 1][i] = max(dp[i][i - 1][i], dp[j][k][j] + a[i] + ycl[j + 1][i - 1] + (a[j + 1] == a[k] ? a[k] : 0));
				//printf("%lld %lld %lld %lld %lld %lld %lld\n", i, dp[i][i - 1][i], dp[j][k][j], a[i], ycl[j + 1][i - 1], a[j + 1] == a[k] ? a[k] : 0, dp[j][k][j] + a[i] + ycl[j + 1][i - 1] + (a[j + 1] == a[k] ? a[k] : 0));
			}
		}
		for(int j = 1; j < i; j++) {
			for(int k = 0; k < j; k++) {
				dp[i][i - 1][i] = max(dp[i][i - 1][i], max(dp[j][k][j] + ycl[j + 1][i - 1] + (a[j + 1] == a[k] ? a[k] : 0), dp[j][j][k] + ycl[j + 1][i - 1]));
				//printf("%lld %lld\n", i, dp[i][i - 1][i]);
			}
		}
	}
	int ans = -1e18;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			ans = max(ans, dp[n][i][j]);
		}
	}
	printf("%lld\n", ans);
}
signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		if(n <= 15) {
			ans = 0;
			dfs(1);
			printf("%lld\n", ans);
		}
		else {
			solve();
		}
	}
}
