#include<bits/stdc++.h>
using namespace std;
int t,n,a[200100],e[1000100],l[200100];
long long dp[200100],sum[200100],num;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	for(int t1=1;t1<=t;t1++)
	{
		memset(dp,0,sizeof(dp));
		memset(e,0,sizeof(e));
		memset(l,0,sizeof(l));
		scanf("%d",&n);
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(e[a[i]])
				l[i]=e[a[i]];
			e[a[i]]=i;
			sum[i]=sum[i-1];
			if(a[i]==a[i-1])
				sum[i]+=a[i];
		}
		for(int i=2;i<=n;i++)
		{
			num=0;
			dp[i]=dp[i-1];
			if(l[i])
			{
				num=dp[l[i]+1]+a[i];
				if(i-1>l[i]+1)
					num+=(sum[i-1]-sum[l[i]]);
			}
			dp[i]=max(dp[i],num);
		}
		cout<<dp[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
