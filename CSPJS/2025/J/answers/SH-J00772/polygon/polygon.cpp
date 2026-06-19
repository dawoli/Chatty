#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, ans = 0, maxn = 0;
int a[5010];
long long fact[5010];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i], maxn = max(a[i], maxn);
		
	fact[0] = 1;
	for(int i = 1;i <= 5000;i ++)
		fact[i] = fact[i - 1] * i % MOD;
	
	
	if(n < 3)
	{
		ans = 0;
	}
	else if(n == 3)
	{
		if(a[1] + a[2] + a[3] > 2 * maxn)
			ans = 1;
		else
			ans = 0;
	}
	else if(maxn == 1)
	{
		for(int i = 3;i <= n;i ++)
		{
			for(int j = 3;j < i;j ++)
			{
				ans += fact[i] / (fact[j] * fact[i - j]) % MOD;					
			}
		}

	}
	else
		ans = 9;
		
	cout << ans << endl;
	return 0;
}
