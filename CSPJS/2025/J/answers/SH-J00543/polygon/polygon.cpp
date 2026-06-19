#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
#define mod 998244353
using namespace std;
ll n;
ll l[5005];
ll ans;
void dfs(int pos, ll num, ll sum, ll mx)
{
	if(pos == n + 1)
	{
		if(sum > 2 * mx && num >= 3)
			ans++, ans %= mod;
		return;
	}
	dfs(pos + 1, num, sum, mx);
	dfs(pos + 1, num + 1, sum + l[pos], max(mx, l[pos]));
}
ll pw(int n, int k)
{
	ll ret = 1;
	for(int i = 1; i <= k; i++)
		ret *= n, ret %= mod;
	return ret;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> l[i];
	if(n <= 20)
		dfs(1, 0, 0, 0);
	else
		ans = pw(2, n) + mod - 1 - n - (n * (n + 1) / 2);
	cout << ans % mod;
	return 0;
}
//please put me on the QIPADASHANG (LG UID: 1029108)
//60pts
