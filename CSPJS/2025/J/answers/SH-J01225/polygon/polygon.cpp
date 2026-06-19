#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
const long long mod = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	sort(a + 1,a + n + 1);
	if (a[n] == 1)
	{
		for (int i = n - 2;i >= 1;i--)
		{
			ans += i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	else
	{
		for (int i = 3;i <= n;i++)
		{
			for (int j = 1;j <= i;j++)
			{
				if (i == 3)
				{
					if (a[j] + a[j + 1] > a[i])
					{
						ans++;
					}
				}
				if (i == 4)
				{
					if (a[j] + a[j + 1] + a[j + 2] > a[i])
					{
						ans++;
					}
				}
				if (i == 5)
				{
					if (a[j] + a[j + 1] + a[j + 2] + a[j + 3] > a[i])
					{
						ans++;
					}
				}
				if (i == 6)
				{
					if (a[j] + a[j + 1] + a[j + 2] + a[j + 3] + a[j + 4] > a[i])
					{
						ans++;
					}
				}
				if (i == 7)
				{
					if (a[j] + a[j + 1] + a[j + 2] + a[j + 3] + a[j + 4] + a[j + 5] > a[i])
					{
						ans++;
					}
				}
				if (i == 8)
				{
					if (a[j] + a[j + 1] + a[j + 2] + a[j + 3] + a[j + 4] + a[j + 5] + a[j + 6] > a[i])
					{
						ans++;
					}
				}
				if (i == 9)
				{
					if (a[j] + a[j + 1] + a[j + 2] + a[j + 3] + a[j + 4] + a[j + 5] + a[j + 6] + a[j + 7] > a[i])
					{
						ans++;
					}
				}
				if (i == 10)
				{
					if (a[j] + a[j + 1] + a[j + 2] + a[j + 3] + a[j + 4] + a[j + 5] + a[j + 6] + a[j + 7] + a[j + 8] > a[i])
					{
						ans++;
					}
				}
			}
		}
		cout << ans % mod;
	}
	return 0;
}
