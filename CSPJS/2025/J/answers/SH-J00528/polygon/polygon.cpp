#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long ans = 0;
long long n;
long long mod = 998244353;
bool T = 1;
bool cmp(long long x,long long y)
{
	return x > y;  
}
void dfs(long long x,long long maxn,long long sum,long long last)
{
	if (x == n)
	{
		if(sum > maxn * 2) ans++;
		ans %= mod;
		return ; 
	} 
	if (x >= 3 && sum > maxn * 2) ans++;
	ans %= mod;
	for (long long i = last + 1;i <= n;i++)
	{
		dfs(x + 1,maxn,sum + a[i],i);
	} 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != 1) T = 0;
	}
	if (T)
	{
		long long mul = 1;
		for (int i = 1;i <= n;i++)
		{
			mul *= 2;
		}
		mul -= n + n *(n - 1) / 2 + n * (n - 1) * (n - 2) / 6;
		cout << mul;
	}
	sort(a + 1,a + n + 1,cmp);
	for (long long i = 1;i <= n - 2;i++)
	{
		dfs(1,a[i],a[i],i);
	}
	cout <<ans;
	return 0;
 } 
