#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 205;
int n, ans;
int dp[N][N][N];
int mx[100005];

struct member {
	int x, y, z;
} a[100005];

void Main() {
	cin >> n;
	memset(dp, 0, sizeof(dp)); ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	if(n >= 205) {
		for(int i = 1; i <= n; i++) mx[i] = max(a[i].x, max(a[i].y, a[i].z));
		sort(mx + 1, mx + n + 1);
		for(int i = n; i > n/2; i--) ans += mx[i];
		cout << ans << endl;
	} else {
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < i; j++) {
				for(int k = 0; j + k < i; k++) {
					dp[j + 1][k][i - j - k - 1] = max(dp[j + 1][k][i - j - k - 1], dp[j][k][i - j - k - 1] + a[i].x);
					dp[j][k + 1][i - j - k - 1] = max(dp[j][k + 1][i - j - k - 1], dp[j][k][i - j - k - 1] + a[i].y);
					dp[j][k][i - j - k - 1 + 1] = max(dp[j][k][i - j - k - 1 + 1], dp[j][k][i - j - k - 1] + a[i].z);
				}
			}
		}
		for(int i = 0; i <= n/2; i++) {
			for(int j = 0; j <= n/2; j++) {
				if(n - i - j > n/2) continue;
				ans = max(ans, dp[i][j][n - i - j]);
	//			cout << i << ' ' << j << ' ' << n - i - j << ' ' << dp[i][j][n - i - j] << endl; 
			}
		}
		cout << ans << endl;
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}
