#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll ans=1;
	for(ll i=1;i<=n;i++)
		ans*=i, ans%=(ll)998244353;
	printf("%lld\n",ans);
	return 0;
}
