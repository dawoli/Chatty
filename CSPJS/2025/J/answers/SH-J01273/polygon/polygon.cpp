#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long dp[10011];
long long a[10011];
long long f[10011];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=10001;j++)f[j]=dp[j];
		for(int j=0;j<=10001;j++)
		{
			if(j+a[i]>=10001)dp[10001]+=f[j],dp[10001]=dp[10001]%N;
			else dp[j+a[i]]+=f[j],dp[j+a[i]]=dp[j+a[i]]%N;
		}
		for(int j=10001;j>=(2LL*a[i]+1);j--)
		{
			ans+=dp[j]-f[j];
			ans=ans%N;
		}
	}
	printf("%lld\n",(ans+N)%N);
	return 0;
}
