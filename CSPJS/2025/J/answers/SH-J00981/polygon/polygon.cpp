#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n, a[5005], cnt;
void dfs(ll maxn,ll step,  ll num, ll c)
{
	if(step > n)
	{ 
		if(c < 3) return;
		if(num > maxn*2) cnt = (cnt+1)%mod;
		return;
	}
	dfs(a[step], step+1, num+a[step],c+1);
	dfs(maxn, step+1, num, c);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	dfs(0, 1, 0, 0);
	cout << cnt%mod;
	return 0;
}
