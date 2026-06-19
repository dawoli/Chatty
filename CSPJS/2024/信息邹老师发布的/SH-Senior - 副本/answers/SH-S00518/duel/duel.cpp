#include <bits/stdc++.h>

using namespace std;

long long n, a[100010], b[100010], c[100010], cnt = 0, d[100010], ans = 0, e[100010];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%lld", &n); 
	for (long long i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i ++ )
	{
		if (b[a[i]] == 0)
		{
			cnt ++ ;
			d[cnt] = a[i];
			b[a[i]] ++ ;
			c[a[i]] ++ ;
			e[a[i]] = cnt;
		}
		else
		{
			b[a[i]] ++ ;
			c[a[i]] ++ ;
		}
	}
	for (long long i = 1; i <= cnt; i ++ )
	{
		for (long long j = i + 1; j <= cnt; j ++ )
		{
			if (b[d[i]] <= c[d[j]])
			{
				b[d[i]] = 0;
				c[d[i]] = 0;
				c[d[j]] -= b[d[i]];
				break;
			}
			else
			{
				b[d[i]] -= c[d[j]];
				if (c[d[i]] >= c[d[j]])
				{
					c[d[i]] -= c[d[j]];	
				}
				else
				{
					c[d[i]] = 0;
				}
				c[d[j]] = 0;
			}
		}
	}
	
	for (long long i = 1; i <= cnt; i ++ )
	{
		ans += b[d[i]];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
