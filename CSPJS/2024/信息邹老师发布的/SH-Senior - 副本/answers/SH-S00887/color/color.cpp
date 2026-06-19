#include<bits/stdc++.h>
using namespace std;

int t,n,a[200010];
long long dp[200010][2],cnt;

long long dfs(int id,int o,int x1,int x2)
{
	if(id==0)
	{
		dp[1][0]=dfs(1,0,0,0);
		dp[1][1]=dfs(1,1,0,0);
		return max(dp[1][0],dp[1][1]);
	}
	if(id==n)
	{
		if(o==0&&a[id]==a[x1])
		{
			dp[id][0]=a[x1];
		}
		if(o==1&&a[id]==a[x2])
		{
			dp[id][1]=a[x2];
		}
		else dp[id][o]=0;
		return dp[id][o];
	}
	
	if(o==0)
	{
		if(a[id]==a[x1])cnt=a[x1];
		dp[id][o]=max(dfs(id+1,0,id,x2),dfs(id+1,1,id,x2))+cnt;
	}
	if(o==1)
	{
		if(a[id]==a[x2])cnt=a[x2];
		dp[id][o]=max(dfs(id+1,0,x1,id),dfs(id+1,1,x2,id))+cnt;
	}
	return dp[id][o];
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	a[0]=0;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=a[n+2]=0;
		cout<<dfs(0,0,0,0);
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=dp[i][1]=0;
		}
	}
	return 0;
}
