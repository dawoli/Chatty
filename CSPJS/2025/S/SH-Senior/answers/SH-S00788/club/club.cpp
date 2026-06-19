
#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005][3];
int dp[1005][505][503];
inline int read()
{
	int f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,cnt;
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		}
		
		for(int i=1;i<=n;i++)
		{			
			for(int k=0;k<=min(i,n/2);k++)
			{
				for(int j=max(i-k-n/2,0);j<=min(i-k,n/2);j++)
				{
					dp[i][k][j]=0;
					if(i-k-j>0)
						dp[i][k][j]=dp[i-1][k][j]+a[i][2];//max(dp[i-1][k-1][j]+a[i][0],dp[i-1][k][j-1]+a[i][1])
					if(k>0)
					{
						dp[i][k][j]=max(dp[i][k][j],dp[i-1][k-1][j]+a[i][0]);
					}
					if(j>0)
						dp[i][k][j]=max(dp[i][k][j],dp[i-1][k][j-1]+a[i][1]);
				}
			}
		}
		for(int i=0;i<=n/2;i++)
		{
			for(int j=n/2-i;j<=n/2;j++)
			{
				ans=max(ans,dp[n][i][j]);
			}
		}
		printf("%d\n",ans);
	 } 
	return 0;
}
