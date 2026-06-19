#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200010];
long long cnt[200010];
long long dp[200010];
int sen[1000010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		memset(sen,0,sizeof(sen));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			cnt[i]=cnt[i-1];
			if(a[i]==a[i-1])cnt[i]+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			if(sen[a[i]]==0)
			{
				sen[a[i]]=i;
				continue;
			}
			int j=sen[a[i]];
			{
				if(a[j]==a[i])
				{
					long long res=0;
					res+=a[i];
					if(j!=i-1)
					{
						res+=dp[j+1];
						res+=(cnt[i-1]-cnt[j+1]);
					}
					else
					{
						res+=dp[j];
					}
					dp[i]=max(dp[i],res);
				}
			}
			sen[a[i]]=i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
