#include <cstdio>
const int N=100100;
const int INF=1e8;
//         0 1 2 3 4 5 6 7 8 9
int w[10]={6,2,5,5,4,5,6,3,7,6};
int c[10]={1,1,1,1,1,1,1,1,1,1};
int dp[N],pre[N];
int zero_cnt[N];
int cnt[20];
int min(int a,int b)
{
	return (a < b) ? a : b;
}
void print(int n,int yuan_n)
{
	if(n==0)
	{
		cnt[0]=zero_cnt[yuan_n];
		int ok=0;
		for(int i=1;i<=9;i++)
		{
			if(cnt[i]>0 && ok==0) ok=i;
		}
		if(ok!=0)
		{
			printf("%d",ok);
			cnt[ok]--;
			for(int i=0;i<=9;i++)
			{
				for(int j=1;j<=cnt[i];j++)
				{
					printf("%d",i);
				}
			}
			printf("\n");
		}
		else
		{
			printf("6");
			cnt[0]--;
			for(int i=1;i<=cnt[0];i++)
			{
				printf("0");
			}
			printf("\n");
		}
		return ;
	}
	if(pre[n]==INF)
	{
		printf("-1\n");
		return ;
	}
	cnt[pre[n]]++;
	print(n-w[pre[n]],yuan_n);
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	dp[0]=0;
	for(int i=1;i<=100000;i++)
	{
		dp[i]=INF;pre[i]=INF;
	}
	for(int i=1;i<10;i++)
	{
		for(int j=w[i];j<=100000;j++) //100000
		{
			if(dp[j]==dp[j-w[i]]+c[i])
			{
				if(j-w[i]>0)
				{
					if(pre[j]>i || pre[j]>pre[j-w[i]])
					{
						pre[j]=min(i,pre[j-w[i]]);
					}
				}
				else
				{
					if(pre[j]>i)
					{
						pre[j]=i;
					}
				}
			}
			if(dp[j]>dp[j-w[i]]+c[i])
			{
				dp[j]=dp[j-w[i]]+c[i];
				if(j-w[i]>0) pre[j]=min(i,pre[j-w[i]]);
				else pre[j]=i;
			}
		}
	}
	for(int j=w[0]+1;j<=100000;j++) //100000
	{
		if(dp[j]==dp[j-w[0]]+c[0])
		{
			if(pre[j]>=pre[j-w[0]])
			{
				dp[j]=dp[j-w[0]]+c[0];
				zero_cnt[j]=zero_cnt[j-w[0]]+1;
			}
		}
		if(dp[j]>dp[j-w[0]]+c[0])
		{
			dp[j]=dp[j-w[0]]+c[0];
			zero_cnt[j]=zero_cnt[j-w[0]]+1;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<10;i++)
		{
			cnt[i]=0;
		}
		if(n==1)
		{
			printf("-1\n");
		}
		else
		{
			print(n,n);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
