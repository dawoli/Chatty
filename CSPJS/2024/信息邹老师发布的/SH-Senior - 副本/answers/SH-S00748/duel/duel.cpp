#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N],sum[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
	    cin>>a[i];
	    sum[a[i]]+=1;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		ans=max(sum[a[i]],ans);
	cout<<ans;
	return 0;
}
