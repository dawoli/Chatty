#include<iostream>
#include<cstring>
using namespace std;
int dp[100005];
int t[15];
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	t[0] = 6;
	t[1] = 2;
	t[2] = 5;
	t[3] = 5;
	t[4] = 4;
	t[5] = 5;
	t[6] = 6;
	t[7] = 3;
	t[8] = 7;
	t[9] = 6;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= 100000; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i - t[j] >= 0)
			{
				dp[i] = min(dp[i], dp[i - t[j]] + 1);
			}
		}
	}
	int tt;
	cin >> tt;
	while (tt-->0)
	{
		int n;
		cin >> n;
		if (dp[n] == 0x3f3f3f3f)
		{
			puts("-1");
			continue;
		}
		int len = dp[n];
		for (int i = 1; i <= len; i++)
		{
			for (int j = (i == 1); j < 10; j++)
			{
				if (n >= t[j] && dp[n] == dp[n - t[j]] + 1)
				{
					putchar('0' + j);
					n -= t[j];
					break;
				}
			}
		}
		putchar('\n');
	}
}
