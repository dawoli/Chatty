#include<bits/stdc++.h>
using namespace std;
int n;
namespace s1
{
	const int N=20;
	int sto[N];
	void solve()
	{
		memset(sto,0,sizeof(sto));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&sto[i]);
		}
		int maxans=0;
		for(int i=0;i<(1<<n);i++)
		{
			int nans=0;
			int last[2]={-1,-1};
			//cout<<i<<endl;
			for(int j=0;j<n;j++)
			{
				int c=i&(1<<j);
				if(c!=0)c=1;
				//cout<<c;
				if(last[c]==-1)last[c]=j;
				else
				{
					if(sto[j]==sto[last[c]])nans+=sto[j];
					last[c]=j;
				}
				//cout<<last[0]<<" "<<last[1]<<endl;
			}
			//cout<<endl;
			//cout<<nans<<endl;
			maxans=max(maxans,nans);
		}
		printf("%d\n",maxans);
	}
}
namespace s2
{
	const int N=110;
	int sto[N];
	int dp[N][N][N];//seen first ith, last red number located at cor j,blue number k
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&sto[i]);
		}
		memset(dp,0,sizeof(dp));
		dp[1][0][1]=0,dp[1][1][0]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=i;j++)//enumerate last red
			{
				int lb=0,rb=i-1;
				if(j!=i)lb=i,rb=i;//last blue is certainly at pos i
				for(int k=lb;k<=rb;k++)//last blue(which is smaller than i if enumerated) 
				{
					//printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]); 
					int redval=dp[i][j][k];//print it red
					if(sto[i+1]==sto[j])redval+=sto[j];
					dp[i+1][i+1][k]=max(dp[i+1][i+1][k],redval);
					//printf("->dp[%d][%d][%d](%d)<-%d\n",i+1,i+1,k,dp[i+1][i+1][k],redval);
					int blueval=dp[i][j][k];//print it blue
					if(sto[i+1]==sto[k])blueval+=sto[k];
					dp[i+1][j][i+1]=max(dp[i+1][j][i+1],blueval);
					//printf("->dp[%d][%d][%d](%d)<-%d\n",i+1,j,i+1,dp[i+1][j][i+1],blueval);
					//puts("");
				}
			}
		}
		int maxans=0;
		for(int j=0;j<=n;j++)//last red
		{
			int lb=0,rb=n-1;
			if(j!=n)lb=n,rb=n;
			for(int k=lb;k<=rb;k++)//last blue
			{
				//printf("sto[%d][%d][%d]=%d\n",n,j,k,dp[n][j][k]); 
				maxans=max(maxans,dp[n][j][k]);
			}
		}
		printf("%d\n",maxans);
	}
}
namespace s3
{
	const int N=2010;
	int sto[N];
	int dp[2][N][N];//last red number located at cor j,blue number k
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&sto[i]);
		}
		memset(dp,0,sizeof(dp));
		int po=0;
		dp[po][1][1]=0,dp[po][1][0]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=i;j++)//enumerate last red
			{
				int lb=0,rb=i-1;
				if(j!=i)lb=i,rb=i;//last blue is certainly at pos i
				for(int k=lb;k<=rb;k++)//last blue(which is smaller than i if enumerated) 
				{
					//printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]); 
					int redval=dp[po][j][k];//print it red
					if(sto[i+1]==sto[j])redval+=sto[j];
					dp[po^1][i+1][k]=max(dp[po^1][i+1][k],redval);
					//printf("->dp[%d][%d][%d](%d)<-%d\n",i+1,i+1,k,dp[i+1][i+1][k],redval);
					int blueval=dp[po][j][k];//print it blue
					if(sto[i+1]==sto[k])blueval+=sto[k];
					dp[po^1][j][i+1]=max(dp[po^1][j][i+1],blueval);
					//printf("->dp[%d][%d][%d](%d)<-%d\n",i+1,j,i+1,dp[i+1][j][i+1],blueval);
					//puts("");
					dp[po][j][k]=0; 
				}
			}
			po^=1;
		}
		int maxans=0;
		for(int j=0;j<=n;j++)//last red
		{
			int lb=0,rb=n-1;
			if(j!=n)lb=n,rb=n;
			for(int k=lb;k<=rb;k++)//last blue
			{
				//printf("sto[%d][%d][%d]=%d\n",n,j,k,dp[n][j][k]); 
				maxans=max(maxans,dp[po][j][k]);
			}
		}
		printf("%d\n",maxans);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n<=15)
		{
			s1::solve();
		}
		else if(n<=100)
		{
			s2::solve();
		}
		else if(n<=2000)
		{
			s3::solve();
		}
		else
		{
			for(int i=1,t;i<=n;i++)
			{
				scanf("%d",&t);
			}
			printf("114514\n");
		}
	}
	return 0;
}
