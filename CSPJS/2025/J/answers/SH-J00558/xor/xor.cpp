#include<bits/stdc++.h>
using namespace std;

const int N=500010;
int n,k;
int a[N]={0};
int sum[N]={0};
int st[N]={0};
int dp[N]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=n;i>=1;i--)
	{
		sum[i]=sum[i+1]^a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0) continue;
		int fnd=sum[i+1]^k;
		for(int j=i;j>=1;j--)
		{
			if(sum[j]==fnd)
			{
				st[i]=j;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(st[i]==0)
		{
			dp[i]=dp[i-1];
			continue;
		}
		
		dp[i]=max(1+dp[st[i]-1],dp[i-1]);
	}
	printf("%d",dp[n]);
	
	return 0;
}
