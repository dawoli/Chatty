#include <bits/stdc++.h>
using namespace std;
int t,n,m,cnt,dp[10005],v[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>v[i][j];
		}
	}
	cnt=m;
	for(int i=1;i<t;i++)
	{
		memset(dp,128,sizeof(dp));
		dp[cnt]=cnt;
		for(int j=1;j<=n;j++)
		{
			for(int k=cnt;k>=v[i][j];k--)
			{
				dp[k-v[i][j]]=max(dp[k-v[i][j]],dp[k]-v[i][j]+v[i+1][j]);
			}
		}
		cnt=*max_element(dp,dp+cnt+1);
	}
	cout<<cnt<<endl;
	return 0;
}