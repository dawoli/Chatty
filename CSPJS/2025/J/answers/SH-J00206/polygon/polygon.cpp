# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
const int N = 5010;
ll n, ans, lst, hhh;
ll a[N], sum[N];
ll dp[N];

ll ksm(ll x, ll y)
{
	ll res;
	res = 1;
	while (y)
	{
		res = (y & 1) ? res * x % mod : res;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1, greater <ll> ());
//	for (int i = 1; i <= n; i++) cout<<a[i]<<endl;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[1]; j >= a[i]; j--)
		{
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
		}
	}
	sum[0] = 0;
	for (int i = 1; i <= a[1]; i++) sum[i] = (sum[i - 1] + dp[i]) % mod;//,cout << sum[i] << " ";
	ans = 0, lst = hhh = 0;
	a[0] = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] == a[lst])
		{
			ll now;
			now = ksm(2ll, n - i);
			hhh++;
//			cout<<now-sum[a[i]]+hhh<<endl;
			ans = (ans + max(0ll, (now + hhh - sum[a[i]] + mod)) % mod) % mod;
			continue;
		}
		hhh = 0;
		//当前任意多边形最长的棍子为a_i 
		ll now;
		now = ksm(2ll, n - i);
//		cout<<now-sum[a[i]]<<endl;
		ans = (ans + max(0ll, now - sum[a[i]] + mod) % mod) % mod;
		lst = i;
	}
	printf("%lld\n", ans);
	return 0;
}
