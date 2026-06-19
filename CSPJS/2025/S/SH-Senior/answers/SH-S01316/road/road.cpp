#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
long long u,v,w;
long long r[10005][10005][2],cs[15][10005];
long long dp[10015],ans;
typedef pair<long long,long long> P;
queue<P> q;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		r[u][v][0]=r[v][u][0]=1;
		r[u][v][1]=r[v][u][1]=w;
	}
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&cs[i][0]);
		for(long long j=1;j<=n;j++)
			scanf("%lld",&cs[i][j]);
	}
	
	for(int i=1;i<=n;i++)
		dp[i]=9e18;
	dp[1]=0;
	q.push(P(1,1));
	while(!q.empty())
	{
		long long t=q.front().first;
		long long c=q.front().second;
		q.pop();
		if(t==1)
		{
			for(long long i=1;i<=k;i++)
				if(dp[c]+cs[i][c]<dp[i+10000])
				{
					dp[i+10000]=dp[c]+cs[i][c];
					q.push(P(2,i));
				}
			for(long long i=1;i<=n;i++)
				if(r[c][i][0]==1)
				{
					if(dp[c]+r[c][i][1]<dp[i])
					{
						dp[i]=dp[c]+r[c][i][1];
						q.push(P(1,i));
					}
				}
		}
		else
			for(long long i=1;i<=n;i++)
				if(dp[c+10000]+cs[c][i]<dp[i])
				{
					dp[i]=dp[c+10000]+cs[c][i];
					q.push(P(1,i));
				}
	}
	for(int i=2;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
