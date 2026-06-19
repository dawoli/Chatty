#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll n,x[N],f[N],cnt=1,q[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&x[i]);
	sort(x+1,x+n+1);
	ll now=x[1];f[1]=1;
	for(ll i=2;i<=n;i++)
	{
		if(x[i]==now)f[cnt]++;
		else f[++cnt]=1,now=x[i];
	}
	q[1]=f[1];
	for(ll i=2;i<=cnt;i++)
	{
		if(f[i]>=q[i-1])q[i]=f[i];
		else q[i]=q[i-1];
	}
	printf("%lld\n",q[cnt]);
	return 0;
}
