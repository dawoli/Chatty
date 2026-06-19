#include <iostream>
#include <cstdio>
using namespace std;

long long n, ans, mod = 998244353;
long long a[22];

bool check(long long num, long long sum, long long maxn)
{
	if (num >= 3 && sum > 2 * maxn)
	{
		return true;
	}
	return false;
}

void dfs(long long dep, long long num, long long sum, long long maxn)
{
	if (dep > n)
	{
		if (check(num, sum, maxn) == true)
		{
			ans += 1;
			ans %= mod;
		}
		return;
	}
	dfs(dep + 1, num + 1, sum + a[dep], max(maxn, a[dep]));
	dfs(dep + 1, num, sum, maxn);
}

long long quick(long long x)
{
	if (x == 1)
	{
		return 2;
	}
	int num = quick(x / 2);
	if (x % 2 == 1)
	{
		return num * num * 2; 
	}
	else
	{
		return num * num;
	}
}

void B()
{
	ans = (quick(n) + mod - 1 - n - n * (n + 1) / 2) % mod;
	cout << ans;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	long long maxn = 0;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (maxn == 1)
	{
		B();
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	/*
	ÃüÔË¾ÍËãµßÅæÁ÷Àë
	ÃüÔË¾ÍËãÇúÕÛÀëÆæ
	ÃüÔË¾ÍËã¿ÖÏÅ×ÅÄã
	×öÈËÃ»È¤Î¶
	±ðÁ÷ÀáÉËÐÄ
	¸ü²»Ó¦ÉáÆú
	ÎÒÔ¸ÄÜÒ»ÉúÓÀÔ¶Åã°éÄã~
	Å¶~Å¶~Å¶Å¶~Å¶Å¶~Å¶Å¶~Å¶Å¶Å¶~Å¶~Å¶Å¶~  
	£¨ÓÐÈ¤µÄÁé»ê£© 
	*/
	
	return 0;
}
