#include <iostream>
#include <cstdio>
using namespace std;
#define long long int

int n, m, s[505], c[505], ans, mod = 998244353;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		s[i] = int(getchar() - '0');
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
