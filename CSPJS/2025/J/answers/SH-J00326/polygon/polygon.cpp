#include <iostream>
using namespace std;

int n, a[5005], ans, ma;

struct node
{
	int maxn;
	int sum, num;
}dp[5005];

void dfs(int step, int maxn, int sum, int cnt)
{
	if (step > n)
	{
		if (sum > maxn * 2 && cnt >= 3)
		{
			ans += 1;
			ans %= 998244353;
		}
		return;
	}
	dfs(step + 1, maxn, sum, cnt);
	dfs(step + 1, max(maxn, a[step]), sum + a[step], cnt + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	if (n <= 20)
	{
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}
	else if (ma <= 1)
	{
		int c = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] >= ma)
			{
				c++;
			}
		}
		for (int i = 3; i <= c; i++)
		{
			long long mul = 1;
			for (int j = c; j >= c - i + 1; j--)
			{
				mul = (mul * j) % 998244353;
			}
			for (int j = 2; j <= i; j++)
			{
				mul /= j;
			}
			ans = (ans + mul) % 998244353;
		}
		cout << ans << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = n; j >= 1; j++)
			{
				if (j - 1 > 0)
				{
					dp[j].maxn = max(dp[j].maxn, dp[j - 1].maxn);
					dp[j].sum = dp[j - 1].sum + a[i];
					if (dp[j].sum > dp[j].maxn * 2)
					{
						dp[j].num = ( dp[j].num + dp[j - 1].num) % 998244353;
					}
				}
			}
		}
		cout << dp[n].num << endl;
	}
	return 0;
}
