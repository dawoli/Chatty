#include <bits/stdc++.h>
using namespace std;
long long n, k, cnt = 0, j = 1, mx = -1;
long long aa[50005], pe[50005];
bool b = false, rff[5005][5005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &aa[i]);
		pe[i] = aa[i] ^ pe[i - 1];
		if (aa[i] <= 1)
		{
			b = true;
		}
	}
	if (b)
	{
		for (int l = 1; l <= n; l++)
		{
			for (int r = l; r <= n; r++)
			{
				if ((pe[r] ^ pe[l - 1]) == k)
				{
					rff[l][r] = true;
				}
			}
		}
		for (int r = 1; r <= n; r++)
		{
			for (int l = j; l <= r; l++)
			{
				if (rff[l][r])
				{
					j = r + 1;
					cnt++;
					break;
				}
			}
		}
	}
	else if (!k)
	{
		for (int i = 1; i <= n; i++)
		{
			if (aa[i] && aa[i + 1])
			{
				i++;
				cnt++;
			}
			else if (!aa[i])
			{
				cnt++;
			}
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (aa[i])
			{
				cnt++;
			}
		}
	}
	printf("%lld", cnt);
	return 0;
}
