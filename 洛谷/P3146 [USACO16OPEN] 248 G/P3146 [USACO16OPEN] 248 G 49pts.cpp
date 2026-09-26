// Problem URL: https://www.luogu.com.cn/problem/P3146
// Finish Time: 2026/9/1 21:30:02 WA 49pts
// Start Time: 2026/9/1 21:15:24

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 248 + 1;

int n, dp[MAXN][MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dp[i][i];
	for (int l = 2; l <= n; l++)
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j	 = i + l - 1;
			dp[i][j] = INT_MIN;
			for (int k = i; k < j; k++)
				dp[i][j] = max({dp[i][j], dp[i][k], dp[k + 1][j], (dp[i][k] == dp[k + 1][j] ? dp[i][k] + 1 : INT_MIN)});
		}
	cout << dp[1][n] << endl;
	return 0;
}

// Deep in the dark, I don't need the light
// There's a ghost inside me
// It all belongs to the other side
// We live, we love, we lie