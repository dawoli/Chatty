// Categories: 动态规划
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string s;
int n,ans=1,dp[10001][10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i+l-1<n;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j])
			{
				dp[i][j]=dp[i+1][j-1]+2;
			}
			else
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}