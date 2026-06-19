#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],pre[500005],p,ans,f=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(n==1)
	{
		if(n==k)printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(n==2)
	{
		ll a,b,c;
		scanf("%lld%lld",&a,&b);
		c=(a^b);
		if(a==k)ans++;
		if(b==k)ans++;
		if(c==k)ans++;
		printf("%lld\n",ans);
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag=0;
	}
	if(flag)
	{
		printf("%lld\n",(n*n)/4);
		return 0;
	}
	for(ll i=1;i<=n;i++)pre[i]=(pre[i-1]^a[i]);
	for(ll r=1;r<=n;r++)
	{
		for(ll l=f;l<=r;l++)
		{
			p=(pre[r]^pre[l-1]);
			if(p==k)
			{
				ans++;
				f=r+1;
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
