// Problem URL: https:/www.luogu.com.cn
// Start Time: 2026/8/10 14:29:57

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 5e2 + 2;

int n, c[MAXN], sum = 0, dp[2][(int)1e5 + 5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		sum += c[i];
	}
	memset(dp, -0xc0, sizeof(dp));
	dp[0][0] = dp[1][0] = 0;
	int MIN				= dp[1][1];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= sum; j++)
		{
#define dp dp[(i - 1) & 1]
			int op1 = MIN;
			if (j + c[i] <= sum)
				op1 = dp[j + c[i]] + c[i];
			int op2 = dp[abs(j - c[i])] + c[i];
			int op3 = dp[j];
#undef dp
			dp[i & 1][j] = max({op1, op2, op3});
		}

	cout << sum - dp[n & 1][0] / 2;
	return 0;
}