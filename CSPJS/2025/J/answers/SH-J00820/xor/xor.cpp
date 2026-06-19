#include<bits/stdc++.h>
using namespace std;
int n,k,a[1001],qzh[1001],cnt=0,dp[1001];
pair <int,int> qj[1000001];//second สื first ฮฒ 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		qzh[i]=qzh[i-1]^a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if ((qzh[j]^qzh[i-1])==k)
			{
				cnt++;
				qj[cnt].second=i;
				qj[cnt].first=j;
			}
		}
	}
	sort(qj+1,qj+cnt+1);
	for (int i=1;i<=cnt;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		if (qj[i-1].first>=qj[i].second)
		{
			for (int j=1;j<i;j++)
			{
				if (qj[j].first<qj[i].second)
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		else dp[i]=max(dp[i],dp[i-1]+1);
	}
	printf("%d",dp[cnt]);
}
