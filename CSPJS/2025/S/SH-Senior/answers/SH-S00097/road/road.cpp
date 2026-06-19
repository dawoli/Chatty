#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
long long u[MAXN], v[MAXN], w[MAXN], c[15], a[15][MAXN];
long long dp[1005][1005];
long long ans[1000005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		dp[u[i]][v[i]] = w[i];
		dp[v[i]][u[i]] = w[i];
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
		for(int j = 1; j < n; j++){
			for(int j2 = j + 1; j2 <= n; j2++){
				dp[j][j2] = min(dp[j][j2], a[i][j] + a[i][j2] + c[i]);
				dp[j2][j] = dp[j][j2];
			}
		}
	}
	int temp = 0;
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			ans[temp++] = dp[i][j];
		}
	}
	sort(ans, ans + temp);
	long long ANS = 0;
	for(int i = 0; i < n - 1; i++){
		ANS += ans[i];
	}
	cout << ANS;
	return 0;
}
