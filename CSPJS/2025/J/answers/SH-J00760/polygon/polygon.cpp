#include <bits/stdc++.h>
using namespace std;
const int modn=998244353;
#define ll long long
ll comb(ll a,ll b)
{
	ll s=1;
	for(int i=1;i<=b;i++)
	{
		s=s*(a-i+1)/i;
	}
	return s%modn;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	int a[5005];
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(ll i=3;i<=n;i++)
	{
		ans=(ans+comb(n,i))%modn;
	}
	cout<<ans;
	return 0;
}
