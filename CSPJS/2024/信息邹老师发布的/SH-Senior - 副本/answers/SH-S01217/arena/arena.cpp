#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long aa[200005];
long long a[200005];
char d[25][200005];
bool dp[200005][25];
long long mx[200005];
long long c[200005];
long long result[200005];
bool isc[200005];
long long x[5];
int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	long long n,m;
	cin>>n>>m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> aa[i];
	}
	for (long long i = 1; i <= m; i++)
	{
		cin >> c[i];
		isc[c[i]] = true;
	}
	long long kk = ceil(log2(n));
	bool flagB = true;
	for (long long i = 1; i <= kk; i++)
	{
		scanf("%s", d[i] + 1);
		for (long long j = 1; j <= (1 << (kk - i)); j++)
		{
			d[i][j] -= '0';
			flagB &= d[i][j] == 0;
		}
	}
	long long tt;
	cin >> tt;
	while (tt-->0)
	{
		for (long long i = 0; i < 4; i++)
		{
			cin >> x[i];
		}
		for (long long i = 1; i <= n; i++)
		{
			a[i] = aa[i] ^ x[i & 3];
			if (isc[i])
			{
				long long tk = ceil(log2(i));
				for (long long j = 0; j < (1 << tk); j++)
				{
					dp[j][0] = true;
				}
				for (long long j = i; j < (1 << tk); j++)
				{
					mx[j] = 0;
				}
				for (long long j = 1; j <= tk; j++)
				{
					for (long long k = 0; k < (1 << (tk - j)); k++)
					{
						long long ma = (k << j) | (d[j][k + 1] << (j - 1));
						long long mb = ma ^ (1 << (j - 1));
						long long mn = 0x3f3f3f3f;
						for (long long l = 0; l < (1 << (j - 1)); l++)
						{
							dp[ma | l][j] = dp[ma | l][j - 1] && ((ma | l) >= i || a[(ma | l) + 1] >= j);
							if (dp[ma | l][j - 1])
							{
								if ((ma | l) >= i)
								{
									mn = min(mn, mx[ma | l]);
									mx[ma | l] = j;
								}
								else
								{
									mn = min(mn, a[(ma | l) + 1]);
								}
							}
						}
						if (mn < j)
						{
							for (long long l = 0; l < (1 << (j - 1)); l++)
							{
								dp[mb | l][j] = dp[mb | l][j - 1];
							}
						}
						else
						{
							for (long long l = 0; l < (1 << (j - 1)); l++)
							{
								dp[mb | l][j] = false;
							}
						}
					}
				}
				result[i] = 0;
				for (long long j = 0; j < (1 << tk); j++)
				{
					if (dp[j][tk])
					{
						result[i] += j + 1;
					}
				}
			}
		}
		long long ans = 0;
		for (long long i = 1; i <= m; i++)
		{
			ans ^= i * result[c[i]];
		}
		cout << ans << endl;
	}
 } 

