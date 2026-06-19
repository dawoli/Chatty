#include <bits/stdc++.h>

using namespace std;

int n;
long long a[500010], k, f[500010], sum[500010], ans = 0;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
		sum[i] = a[i] ^ sum[i - 1];
	}
	for (int i = 1; i <= n; i ++ )
	{
		f[i] = f[i - 1];
		for (int j = i; j >= 1; j -- )
		{
			if ((sum[i] ^ sum[j - 1]) == k)
			{
				f[i] = max(f[i], f[j - 1] + 1);
				break;
			}
		}
	}
	
	printf("%d\n", f[n]);
	return 0;
}
