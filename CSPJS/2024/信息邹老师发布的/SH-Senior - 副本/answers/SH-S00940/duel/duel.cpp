#include<bits/stdc++.h>
#define INF 2e9
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,a[N],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll l=1,r=2;r<=n;r++)
	{
		if(a[l]==a[r]) continue;
		ans++,l++;
	}
	printf("%lld\n",n-ans);
	return 0;
}
