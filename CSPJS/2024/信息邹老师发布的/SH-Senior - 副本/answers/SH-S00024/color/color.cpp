#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 200005

int n;
int a[N];

int col[N];
int ans = 0;

void dfs(int x) {
	if (x > n) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				if (col[j] == col[i]) {
					if (a[i] == a[j]) {
						res += a[i];
					}
					break;
				}
			}
		}
		ans = max(ans, res);
		return;
	}
	col[x] = 0;
	dfs(x + 1);
	col[x] = 1;
	dfs(x + 1);
}

void brute() {
	ans = 0;
	dfs(1);
	cout << ans << endl;
}


int dp[200005];
void dp0() {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 2; j++) {
			dp[i - 1] = max(dp[i - 1], dp[j] + (a[i] == a[j] ? a[i] : 0));
		}
		for (int j = 1; j <= i - 2; j++) {
			dp[j] += (a[i] == a[i - 1] ? a[i] : 0);
		}
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]); 
	}
	cout << ans << endl;
}

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n <= 15) {
			brute();
		} else {
			dp0();
		}
	}
}
