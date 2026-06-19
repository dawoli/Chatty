#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 998244353

ll ans = 0;
ll n; ll arr[5005];

ll calu( ll j)
{
	ll tmp = 1;
	for (int i = n; i > n - j; i--)
	{
		tmp = (tmp * (i % mod)) % mod;
	}
	for (int i = j; i > 1; i--)
	{
		tmp /= i;
	}
	return tmp % mod;
}

void dfs(ll dep, ll max_val, ll sum, ll ch)
{
	if (dep == n)
	{
		if (max_val * 2 < sum && ch >= 3)
		{
			ans++;
			ans %= mod;
		}
		return;
	}
	
	dfs(dep +1, max_val, sum, ch);
	dfs(dep + 1, max(max_val, arr[dep]), sum + arr[dep], ch + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 0 ; i < n; i++) cin >>arr[i];
	
	if (n <= 20)
	{
		dfs(0, 0, 0, 0);
		cout << ans << endl;
	}
	else 
	{
		for (int i = 3; i <= n; i++)
		{
			ans += calu(i);
			ans %= mod;
		}
		cout << ans << endl;
	}
	
	return 0;
} 
