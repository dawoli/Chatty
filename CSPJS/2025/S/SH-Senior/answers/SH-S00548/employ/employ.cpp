#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m, c[512], id[512], na[512];
long long ans = 0;
char s[512];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++ )
	{
		id[i] = i;
		na[i] = s[i] - '0';
		scanf("%d", &c[i]);
	}
	do
	{
		int cnt = 0, tot = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (cnt >= c[id[i]] || na[i] == 0)
			{
				cnt ++ ;
				continue;
			}
			else
			{
				tot ++ ;
			}
		}
		if (tot >= m)
		{
			ans ++ ;
		}
		if (ans >= mod)
		{
			ans -= mod;
		}
	}while(next_permutation(id + 1, id + n + 1));
	printf("%lld\n", ans % mod);
	return 0;
}
