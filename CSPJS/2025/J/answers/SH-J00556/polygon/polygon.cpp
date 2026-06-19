#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, a[5010], maa = 0;
long long ans = 0;

long long qmi(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		maa = max(maa, a[i]);
	}
	if (maa == 1)
	{
		printf("%lld\n", qmi(2, n) - n - n * (n - 1) / 2 - 1);
		return 0;
	}
	for (int i = 0; i < (1 << n); i ++ )
	{
		int sum = 0, ma = 0, cnt = 0;
		for (int j = 0; j < n; j ++ )
		{
			if (i >> j & 1)
			{
				ma = max(ma, a[j + 1]);
				sum += a[j + 1];
				cnt ++ ;
			}
		}
		if (sum > 2 * ma && cnt >= 3)
		{
			ans ++ ;
		}
		if (ans >= mod)
		{
			ans -= mod;
		}
	}
	printf("%lld\n", ans % mod);
	
	return 0;
}
