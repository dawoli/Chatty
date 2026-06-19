#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll n,a[5005],sum,ercf,ans,dp[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>2)
		{
			for(int j=0;j<=a[i];j++)
			{
				sum+=dp[j];
				sum%=MOD;
			}	
		}
		for(int j=5000;j>=a[i];j--)
		{
			if(dp[j-a[i]])
			{
				dp[j]+=dp[j-a[i]];
				dp[j]%=MOD;
			}
		}
		//cout<<sum<<endl;
	}
	ercf=1;
	for(int i=1;i<=n;i++)
	{
		ercf*=2;
		ercf%=MOD;
	}
	ans=(ercf+MOD+MOD-4-sum)%MOD;
	printf("%lld",ans);
	return 0;
}
