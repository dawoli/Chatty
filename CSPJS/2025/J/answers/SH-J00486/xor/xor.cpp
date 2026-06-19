#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,a[500009],sum[500009],mn[500009],dp[500009];

ll sub(ll a,ll b)
{
	ll ca[109]={0},cb[109]={0},c[109]={0};
	ll cnta=-1,cntb=-1,res=0;
	while(a)
	{
		ca[++cnta]=a%2;
		a/=2;
	}
	while(b)
	{
		cb[++cntb]=b%2;
		b/=2;
	}
	for(int i=0;i<=max(cnta,cntb);i++)
	{
		if(ca[i]==0&&cb[i]==1)
			c[i]=1;
		else if(ca[i]==1&&cb[i]==0)
			c[i]=1;
		else if(ca[i]==1&&cb[i]==1)
			c[i]=0;
		else c[i]=0;
	}
	for(int i=max(cnta,cntb);i>=0;i--)
	{
		res*=2;
		res+=c[i];
	}
	return res;
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(dp,0,sizeof(dp));
	memset(mn,-1,sizeof(mn));
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
			sum[i]=a[i];
		else sum[i]=sum[i-1]^a[i];
//		printf("%lld ",sum[i]);
	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		ll pos=-1;
		for(int j=i;j<=n;j++)
			if(sub(sum[j],sum[i-1])==k)
			{
				pos=j;
				break;
			}
//		printf("%lld ",pos);
		if(pos==-1)
			continue;
		mn[pos]=max((ll)i,mn[pos]);
	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(mn[i]!=-1)
			dp[i]=max(dp[i-1],dp[mn[i]-1]+1);
//		printf("%lld ",dp[i]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
