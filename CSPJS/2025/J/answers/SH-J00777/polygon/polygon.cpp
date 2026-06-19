#include <bits/stdc++.h>
using namespace std;
int n, a[5000], mak = 0;
long long solve(int c, int s, int maxx, int t)
{
	if(t == n)
	{
		if(c >= 3 && s > maxx * 2)
			return 1;
		else
		return 0;
	}
	if(a[t] > maxx)
		return solve(c + 1, s + a[t], a[t], t + 1) + solve(c, s, maxx, t + 1);
	else
		return solve(c + 1, s + a[t], maxx, t + 1) + solve(c, s, maxx, t + 1);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		mak = max(mak, a[i]);
	}
	if(mak == 1)
	{
		double s = 0;
		for(int i = 3; i <= n; i++)
		{
			for(int j = n; j > n - i; j--)
				s = s + double(j) / double(i + j - n);
		}
		long long k = s;
		printf("%lld\n", k);
		return 0;
	}
	printf("%lld\n", solve(0, 0, 0, 0) % 998244353);
	return 0;
}
