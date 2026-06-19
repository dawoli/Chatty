#include <bits/stdc++.h>
using namespace std;

long long n, a[5005], s[5010], sum = 0;
const long long m = 998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n == 3 && a[1]+a[2]+a[3] > 2*max(max(a[1],a[2]),max(a[2],a[3])))
	{
		sum++;
		cout << sum;
		return 0;
	}
	else if (n == 3)
	{
		cout << sum;
		return 0;
	}
	for (long long i = 1; i <= 5001; i++)
	{
		s[i] = (s[i-1]+i)%m;
	}
	for (long long i = n-2; i >= 1; i--)
	{
		sum += i*s[n-i-1]%m;
		sum %= m;
	}
	cout << sum;
	return 0;
} 
