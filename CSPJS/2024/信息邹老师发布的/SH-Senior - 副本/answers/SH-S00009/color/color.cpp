#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,a[200010],flag[200010],dp[200010],pre[1000010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
			scanf("%lld",a+i);
		memset(pre,0,sizeof(pre));
		for(long long i=1;i<=n;i++)
		{
			if(pre[a[i]]==0)
				flag[i]=0;
			else
				flag[i]=pre[a[i]];
			pre[a[i]]=i;
		}
		for(long long i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			if(flag[i]==0)
				continue;
			dp[i]=dp[flag[i]]+a[i];
			long long t=0;
			for(long long j=flag[i]+1;j<i;j++)
			{
				if(t==0 && j>flag[i]+1 && a[j]!=a[j-1])
					t=1;
				if(t==1)
				{
					if(flag[j]==j-1)
						dp[i]+=a[j];
				}
				if(t==0)
					dp[i]+=a[flag[j]];
			}
			dp[i]=max(dp[i-1],dp[i]);
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
