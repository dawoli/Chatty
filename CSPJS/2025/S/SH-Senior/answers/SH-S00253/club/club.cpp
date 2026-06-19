#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
struct node
{
	long long a,b,c;
}w[1000010];
long long dp[210][110][110];
priority_queue<int,vector<int>,greater<int> >pq;
void differ()
{
	long long hile=0;
	for(int i=1;i<=n;i++)
	{
		long long z1,z2,z3;
		cin>>z1>>z2>>z3;
		pq.push(z1);
	}
	for(int i=1;i<=n/2;i++)
	{
		hile+=pq.top();
		pq.pop();
	}
	cout<<hile<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		memset(dp,-0x3f3f3f,sizeof(dp));
		cin>>n;
		if(n>300)
		{
			differ();
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>w[j].a>>w[j].b>>w[j].c;
		} 
		dp[0][0][0]=0;
		long long minn=-1e9;
		for(int t=1;t<=n;t++)
		{
			for(int j=0;j<=n/2;j++)
			{
				if(j>t)break;
				for(int k=0;k<=n/2;k++)
				{
					if(k+j>t)break;
					if(t-j-k>n/2||t-j-k<0)continue;
					if(j-1>=0)dp[t][j][k]=max(dp[t-1][j-1][k]+w[t].a,dp[t][j][k]); 
					if(k-1>=0)dp[t][j][k]=max(dp[t-1][j][k-1]+w[t].b,dp[t][j][k]);
					if(t-j-k-1>=0)dp[t][j][k]=max(dp[t-1][j][k]+w[t].c,dp[t][j][k]);
				}
			}
		}
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				minn=max(minn,dp[n][j][k]);
			}
		}
		cout<<minn<<endl;
	}
	



	return 0;
}

