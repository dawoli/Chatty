#include<bits/stdc++.h> 
using namespace std;
#define ll long long
ll a[1000010];
ll ss[1000010];
ll dp[1000010];
ll maxn[1000100];
ll ans;
bool A = 1;
bool B = 1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin >> n >> k;
	for (ll i = 1;i <= n;i++)
	{
		cin >> a[i];
		ss[i] = ss[i - 1] ^ a[i];
		if (a[i] != 1)
		{
			A = 0;
			if (a[i] != 0)
			{
				B = 0;
			}
		}
	}
	if (B)
	{
		ll num1 = 0,num0 = 0,t = 0;
		for (ll i = 1;i <= n;i++)
		{
			if (a[i] == 1) num1++,t++;
			if (a[i] == 0)
			{
				num0++;
				num0 += t / 2;
				t= 0;
			}
		}
		if (k == 1) cout << num1;
		else cout << num0;
		return 0;
	}
	if (A)
	{
		cout << n / 2;
		return 0;
	}
	for (ll l = 1;l <= n;l++)
	{
		for (ll r = l;r <= n;r++)
		{
			ll x = ss[r] ^ ss[l - 1];
			if (x == k)
			{
				dp[r] = max(dp[r],maxn[l - 1] + 1);
				for (ll i = r;i <= n;i++)
				{
					maxn[i] = max(maxn[i],dp[r]);
				}
			}
		}
	}
	for (ll i = 1;i <= n;i++)
	{
		ans = max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
