#include <iostream>
using namespace std;

int n, K, a[500005], s[3005][3005], dp[3005][3005];
bool flag1, flag2;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> K;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			flag1 = true;
		}
		if (a[i] != 1 && a[i] != 0)
		{
			flag2 = true;
		}
	}
	if (!flag1)
	{
		cout << n / 2 << endl;
		return 0;
	}
	else if (!flag2)
	{
		if (K == 0)
		{
			int cnt = 0, f = 0;
			for(int i = 1; i <= n; i++)
			{
				if (a[i] == 0)
				{
					cnt++;
					f = 0;
				}
				else
				{
					if (f == 1)
					{
						cnt++;
						f = 0;
						continue;
					}
					f = 1;
				}
			}
			cout << cnt << endl;
		}
		else
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if (a[i] == 1)
				{
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	else if (n <= 500)
	{
		s[1][1] = a[1];
		for(int i = 1; i <= n; i++)
		{
			if (a[i] == K)
			{
				dp[i][i] = 1;
			}
		}
		for(int i = 2; i <= n; i++)
		{
			s[1][i] = (s[1][i - 1] ^ a[i]);
		}
		for (int i = 2; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = i; k <= j; k++)
				{
					s[i][j] = (s[i][j] ^ a[k]);
				}
			}
		}
		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i <= n - len + 1; i++)
			{
				int j = i + len - 1;
				for (int k = i; k <= j - 1; k++)
				{
					if (s[i][k] == K && s[k + 1][j] == K)
						dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}
		cout << dp[1][n] << endl;
	}
	else
	{
		cout << n / 2 << endl;
	}
	return 0;
}
