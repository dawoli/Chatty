#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5005];
const long long mod=998244353;
long long dp[2][10005],ans,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		bool tmp=i&1;
		for(int j=0;j<=min(1ll*10001,sum);j++)dp[tmp][j]=0;
		for(int j=0;j<=min(1ll*10001,sum);j++)
		{
			dp[tmp][j]+=dp[!tmp][j];
			dp[tmp][j]%=mod;
			dp[tmp][min(10001,j+a[i])]+=dp[!tmp][j];
			dp[tmp][min(10001,j+a[i])]%=mod;
			if(j+a[i]>2*a[i])
			{
				ans=(ans+dp[!tmp][j])%mod;
			}
		}
		sum+=a[i];
	}
	printf("%lld",ans);
	return 0;
}
/*
6
2 2 4 13 16 17
*/

