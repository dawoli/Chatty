#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll R=1e5+10;
ll n,cnt[R],mxr,ans;
vector<ll> vec;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		ll r;
		scanf("%lld",&r);
		cnt[r]++;
		mxr=max(mxr,r);
	}
	for(ll i=1;i<=mxr;i++)
		if(cnt[i]) vec.push_back(i);
	ll a=cnt[vec[0]];
	for(ll i=1;i<vec.size();i++)
	{
		ll now=cnt[vec[i]];
		if(now>=a)
		{
			ans+=a;
			a=now;
		}
		else ans+=now;
	}
	ans=n-ans;
	printf("%lld",ans);
	return 0;
}
