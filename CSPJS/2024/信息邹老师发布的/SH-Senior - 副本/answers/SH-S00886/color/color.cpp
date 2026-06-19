#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
using namespace std;

typedef long double db;
typedef pair<int, int> PII;
void file_IO(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
}

const int N = 2e5 + 10;
int T, n, a[N], sum[N], dp[N][2];
int tot = 0, maxn = 0, mx[N], t[N];

void solve(){
	cin >> n, tot = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i], t[++tot] = a[i];
		sum[i] = sum[i - 1] + (a[i] == a[i - 1] ? a[i] : 0);
	}
	sort(t + 1, t + tot + 1);
	tot = unique(t + 1, t + tot + 1) - t - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(t + 1, t + tot + 1, a[i]) - t;
	maxn = 0, memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= tot; i++)
		mx[i] = -1e18;
	for (int i = 1; i <= n; i++){
		dp[i][0] = max(dp[i][0], max(dp[i - 1][0], dp[i - 1][1]) + (a[i - 1] == a[i] ? t[a[i]] : 0));
		if (i >= 2){
			dp[i][1] = max(dp[i][1], sum[i - 1] + maxn);
			if (mx[a[i]] != -1e18)
				dp[i][1] = max(dp[i][1], mx[a[i]] + sum[i - 1] + t[a[i]]);
		}
		maxn = max(maxn, dp[i][1] - sum[i]);
		mx[a[i - 1]] = max(mx[a[i - 1]], dp[i][1] - sum[i]);
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}

signed main(){
	file_IO();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T --> 0)
		solve();
	return 0;
}
//IANYEYZ AK IOI
