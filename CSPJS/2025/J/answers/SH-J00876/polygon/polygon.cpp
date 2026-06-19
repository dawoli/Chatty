#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxx,sum;
long long ans;
void solve1()
{
	for (int i = 0;i < n;i++)
	{
		sum += a[i];
		maxx = max(maxx,a[i]);
	}
	if (sum > maxx * 2)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
	}
	return;
}
void solve2()
{
	for (int i = 1;i < (1 << n);i++)
	{
		sum = 0;
		maxx = -12;
		if (__builtin_popcount(i) < 3)
		{
			continue;
		}
		for (int j = 0;j < n;j++)
		{
			if (i >> j & 1)
			{
                maxx = max(maxx,a[j]);
                sum += a[j];
			}
		}
		if (sum > 2 * maxx)
		{
		    ans++;
			ans %= 998244353;	
		}
	}
	cout << ans;
	return;
}
void solve3()
{
	ans = 1;
	for (int i = 3;i <= n;i++)
	{
		for (int j = n;j >= n - i + 1;j--)
		{
	        ans *= j;
			ans %= 998244353;	
		}
		for (int j = i;j >= 1;j--)
		{
	        ans /= j;		
		}
	}
	cout << ans;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag = true;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
    	cin >> a[i];
    	if (a[i] != 1)
    	{
    		flag = false;
		}
	}
	if (n == 3)
	{
		solve1();
	}
	else if (n <= 20)
	{
		solve2();
	}
	else if(flag)
	{
		solve3();
	}
	return 0;
}
