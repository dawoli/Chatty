#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 509;
const int M = 18;
int n,m,d[N],c[N],p[N],popcnt[1<<M],f[1<<M][M+1],ans,num[N],snum[N];
ll fac(int x)
{
	if (x <= 1) return 1;
	return x * fac(x - 1) % mod;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%1d", &d[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	if (n <= 18)
	{
		int nPtn = (1 << n);
		f[0][0] = 1;
		for (int p = 1; p < nPtn; ++p)
		{
			int i = popcnt[p] = popcnt[p >> 1] + (p & 1);
			for (int j = 0; j < n; ++j) if (p >> j & 1) for (int k = 0; k < i; ++k) (f[p][k + (d[i] && i - 1 - k < c[j])] += f[p - (1 << j)][k]) %= mod;
		}
		for (int k = m; k <= n; ++k) (ans += f[nPtn - 1][k]) %= mod;
		printf("%d\n", ans);
		return 0;
	}
	if (m == n)
	{
		printf("%lld\n", *min_element(c, c + n) ? fac(n) : 0);
		return 0;
	}
	if (m == 1)
	{
		for (int i = 0; i < n; ++i) ++num[c[i]];
		snum[0] = num[0];
		for (int i = 1; i <= n; ++i) snum[i] = snum[i - 1] + num[i];
		int n0 = 0;
		ll ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (!d[i])
			{
				++n0;
				continue;
			}
			(ans *= snum[i - 1] - i + 1 + n0) %= mod;
		}
		printf("%lld\n", ((fac(n) - ans * fac(n0) % mod) % mod + mod) % mod);
		return 0;
	}
	return 0;
}