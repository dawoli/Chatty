#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 998244353
int n, a[50001];
int C(int n, int m)
{
	ll mul = 1;
	if (m > n / 2)
	{
		for (int i = m + 1; i <= n; i++) mul *= i;
		for (int i = 1; i <= n - m; i++) mul /= i;
		return mul;
	}
	else
	{
		for (int i = n - m + 1; i <= n; i++) mul *= i;
		for (int i = 1; i <= m; i++) mul /= i;
		return mul;
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[n] == 1)
	{
		ll ans = 0;
		for (int i = 3; i <= n; i++)
			ans = (ans + C(n, i) % mod) % mod;
		cout << ans;
		return 0;
	}
	return 0;
}
/*
累了，不会  写个特殊性质走人 
*/
