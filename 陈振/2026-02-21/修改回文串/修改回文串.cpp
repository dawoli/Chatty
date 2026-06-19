// Categories: 动态规划
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string s;
int n,dp[1001][1001];
void Main()
{
	cin>>s;
	n=s.size();
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i+l-1<n;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
			else dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
		}
	}
	cout<<dp[0][n-1]<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while (t--)
	{
		Main();
	}
	return 0;
}