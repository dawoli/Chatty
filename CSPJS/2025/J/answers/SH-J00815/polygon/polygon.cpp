#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int n;
int a[5005];
int maxa = 0;
int dp[5005]; //dp[j] 表示枚举到目前的i的大于等于j的组合个数； 
//转移：枚举到i项a[i]， dp[j] += dp[j - a[i]];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		maxa = max(maxa, a[i]);
	}
	sort(a + 1, a + n + 1);
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i] + 1; j <= maxa + 1; j++)
			ans = (ans + dp[j]) % MOD;
		for (int j = maxa + 1; j >= maxa - a[i] + 1; j--)
			dp[maxa + 1] = (dp[maxa + 1] + dp[j]) % MOD;
		for (int j = maxa; j >= a[i]; j--)
			dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
