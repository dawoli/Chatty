#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 507, mod = 998244353;
int n, m, a[N], dp[1 << 19][27], ans, ct;
bool f[N];
char c;
int calc(int x)
{
	int res = 1;
	for(int i = 1; i <= x; i++)
		(res *= i) %= mod;
	return res;
}
int cal(int x)
{
	int res = 0;
	while(x)
	{
		res += x % 2;
		x /= 2;
	}
	return res;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> c, f[i] = c - '0', ct += f[i];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(ct == n)
		return cout << calc(n), 0;
	dp[0][0] = 1; 
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(!((i >> (k - 1)) & 1))
					(dp[i | (1 << (k - 1))][j + (a[k] <= j || !f[cal(i) + 1])] += dp[i][j]) %= mod;
	for(int i = 0; i <= n - m; i++)
		(ans += dp[(1 << n) - 1][i]) %= mod; 
	cout << ans;
	return 0;
}
// ÉÙÓðÅ£±Æ 
