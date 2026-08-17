// Problem URL: https://www.luogu.com.cn/problem/P1373
// Finish Time: 2026/8/12 13:55:03 AC
// Finish Time: 2026/8/12 13:50:22 WA 80pts
// Finish Time: 2026/8/12 13:46:58 WA 40pts
// Start Time: 2026/8/12 13:21:30

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 8e2 + 2;
const int		  MAXK = 16;
const int		  MOD  = 1e9 + 7;

int n, m, k;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXK][2];
int ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	k++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][a[i][j] % k][0] = 1;
			for (int l = 0; l <= k; l++)
			{
				dp[i][j][l][0] = (dp[i][j][l][0] + dp[i - 1][j][(l - a[i][j] + k) % k][1]) % MOD;
				dp[i][j][l][0] = (dp[i][j][l][0] + dp[i][j - 1][(l - a[i][j] + k) % k][1]) % MOD;
				dp[i][j][l][1] = (dp[i][j][l][1] + dp[i - 1][j][(l + a[i][j]) % k][0]) % MOD;
				dp[i][j][l][1] = (dp[i][j][l][1] + dp[i][j - 1][(l + a[i][j]) % k][0]) % MOD;
			}
			ans += dp[i][j][0][1];
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}