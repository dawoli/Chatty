#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5010;
const long long mod=998244353;
long long dp[N];
int a[N];
long long quick_pow(long long a,long long b,long long mod)
{
	if(b==0) return 1;
	long long ans=quick_pow(a,b>>1,mod);
	ans=ans*ans%mod;
	if(b&1) ans=ans*a%mod;
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=3)
		{
			long long cnt=0;
			for(int j=0;j<=a[i];j++)
			{
				cnt=(cnt+dp[j])%mod;
			}
			ans=(ans+quick_pow(2,i-1,mod)-cnt+mod)%mod;
		}
		for(int j=a[n]/*mention!*/;j>=a[i];j--)
		{
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
