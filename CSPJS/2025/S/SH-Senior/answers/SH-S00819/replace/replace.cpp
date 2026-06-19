#include <bits/stdc++.h>
using namespace std;
const int p = 101;
const int MOD = 998244353;
int n, q;


char s1[1005][2005], s2[1005][2005];
int sl[1005];
int hashs1[1005][2005], hashs2[1005][2005];
char t1[5000005], t2[5000005];
int hasht1[5000005], hasht2[5000005];
int mulp[5000005];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	mulp[0] = 1;
	for (int i = 1; i <= 5000000; i++)
	{
		mulp[i] = 1ll * mulp[i - 1] * p % MOD;
	}
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%s", s1[i] + 1, s2[i] + 1);
		sl[i] = strlen(s1[i] + 1);
		for (int j = 1; j <= sl[i]; j++)
		{
			hashs1[i][j] = (1ll * hashs1[i][j - 1] * p + s1[i][j] - 'a' + 1) % MOD;
			hashs2[i][j] = (1ll * hashs2[i][j - 1] * p + s2[i][j] - 'a' + 1) % MOD;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%s%s", t1 + 1, t2 + 1);
		int tl1 = strlen(t1 + 1);
		int tl2 = strlen(t2 + 1);
		if (tl1 != tl2)
			puts("0");
		else
		{
			for (int j = 1; j <= tl1; j++)
			{
				hasht1[j] = (1ll * hasht1[j - 1] * p + t1[j] - 'a' + 1) % MOD;
				hasht2[j] = (1ll * hasht2[j - 1] * p + t2[j] - 'a' + 1) % MOD;
			}
			int ans = 0;
			for (int j = 1; j <= tl1; j++)
			{
				if (t1[j - 1] != t2[j - 1]) break;
				for (int k = 1; k <= n; k++)
				{
					if (j + sl[k] - 1 > tl1) continue;
					if (hashs1[k][sl[k]] == ((hasht1[j + sl[k] - 1] - 1ll * hasht1[j - 1] * mulp[sl[k]]) % MOD + MOD) % MOD)
					{
						if (hashs2[k][sl[k]] == ((hasht2[j + sl[k] - 1] - 1ll * hasht2[j - 1] * mulp[sl[k]]) % MOD + MOD) % MOD)
						{
							if (((hasht1[tl1] - 1ll * hasht1[j + sl[k] - 1] * mulp[tl1 - j - sl[k] + 1]) % MOD + MOD) % MOD == ((hasht2[tl2] - 1ll * hasht2[j + sl[k] - 1] * mulp[tl2 - j - sl[k] + 1]) % MOD + MOD) % MOD)
							{
								ans++;
							}
						}
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
