#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
int n,a[100005][4];
int dp[MAXN][MAXN];
int tmp[100005];
void solve1()
{
	int i,j,k;
	int ans=0;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=i;j>=0;j--)
		{
			for(k=i-j;k>=0;k--)
			{
				dp[j][k]=dp[j][k]+a[i][3];
				if(j>0) dp[j][k]=max(dp[j][k],dp[j-1][k]+a[i][1]);
				if(k>0) dp[j][k]=max(dp[j][k],dp[j][k-1]+a[i][2]);
				
			}
		}
	}
	for(j=0;j<=n;j++)
	{
		for(k=0;k<=n;k++)
		{
			if(j<=n/2 && k<=n/2 && (n-j-k+1)<=n/2)
				ans=max(ans,dp[j][k]);
		}
	}
	printf("%d\n",ans);
}
void solve2()
{
	int i;
	long long ans=0;
	for(i=1;i<=n;i++)
	{
		tmp[i]=a[i][1];
	}
	sort(tmp+1,tmp+1+n);
	for(i=n;i>n/2;i--) ans+=tmp[i];
	printf("%d\n",ans);
}
void work()
{
	int i;
	bool f=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		if(f && (a[i][2]+a[i][3])!=0) f=0;
	}
	if(f)
	{
		solve2();
	}
	else
	{
		solve1();
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,t;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		work();
	}
	return 0;
}
