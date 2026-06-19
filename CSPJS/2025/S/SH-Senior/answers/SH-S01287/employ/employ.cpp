#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long dp[300011][21];
char s[101];
int a[101];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=0;i<=(1<<n)-1;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(dp[i][j]==0)continue;
			for(int k=1;k<=n;k++)
			{
				if((i&(1<<(k-1)))==0)
				{
					if(a[k]<=j||(s[(__builtin_popcount(i))+1]=='0'))
					dp[i+(1<<(k-1))][j+1]+=dp[i][j],dp[i+(1<<(k-1))][j+1]=dp[i+(1<<(k-1))][j+1]%N;
					else dp[i+(1<<(k-1))][j]+=dp[i][j],dp[i+(1<<(k-1))][j]=dp[i+(1<<(k-1))][j]%N;
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=n-m;i++)ans+=dp[(1<<n)-1][i],ans=ans%N;
	printf("%lld\n",ans);
}
