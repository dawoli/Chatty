#include <cstdio>
const int mod=998244353;
const int N=510;
int c[N];
char s[N];
int dp[(1<<18)+20][20];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int okA=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') okA=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					cnt++;
				}
			}
			for(int k=0;k<=cnt;k++)
			{
				for(int j=1;j<=n;j++)
				{
					if((i&(1<<(j-1)))==0)
					{
						if(s[cnt+1]=='1' && cnt-k<c[j])
						{
							dp[i|(1<<(j-1))][k+1]=(dp[i|(1<<(j-1))][k+1]+dp[i][k])%mod;
						}
						else
						{
							dp[i|(1<<(j-1))][k]=(dp[i|(1<<(j-1))][k]+dp[i][k])%mod;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)
		{
			ans=ans+dp[(1<<n)-1][i];
			if(ans>=mod) ans-=mod;
		}
		printf("%d\n",ans);
	}
	else if(m==1)
	{
		
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0) okA=0;
		}
		if(okA==0)
		{
			printf("0\n");
		}
		else
		{
			long long ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=ans*i%mod;
			}
			printf("%lld\n",ans);
		}
	}
	else if(okA==1)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
