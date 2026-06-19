#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
long long C(int a, int b)
{
	long long res = 1;
	for (int i = a; i >= a - b + 1; i--)
		res *= i;
	for (int i = 1; i <= b; i++)
		res /= i;
	return res % mod;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool sp = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i > 1 && a[i] != a[i - 1])
			sp = 0;
	}
	if (n <= 2)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		cout << (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]);
		return 0;
	}
	if (n == 4)
	{
		cout << (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) + (a[1] + a[2] > a[4] && a[1] + a[4] > a[2] && a[2] + a[4] > a[1]) + (a[1] + a[3] > a[4] && a[1] + a[4] > a[3] && a[3] + a[4] > a[1]) + (a[2] + a[3] > a[4] && a[2] + a[4] > a[3] && a[3] + a[4] > a[2]) + (a[1] + a[2] + a[3] > a[4] && a[1] + a[2] + a[4] > a[3] && a[1] + a[3] + a[4] > a[2] && a[2] + a[3] + a[4] > a[1]);
		return 0;
	}
	if (sp)
	{
		long long sum = 0;
		for (int i = 3; i <= n; i++)
			sum = (sum + C(n, i)) % mod;
		cout << sum;
		return 0;
	}
	return 0;
}
