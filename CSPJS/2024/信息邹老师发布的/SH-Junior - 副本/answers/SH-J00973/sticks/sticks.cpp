#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n,dp[100005];
		cin >> n;
		if(n<=1)
		{
			cout << -1 << endl;
			continue;
		}
		for(int j=1;j<=n;j++) dp[j]=10000000;
		dp[0]=0;
		for(int j=2;j<=n;j++)
		{
			if(j-2!=1) dp[j]=dp[j-2]*10+1;
			if(j>=3&&j-3!=1) dp[j]=min(dp[j],dp[j-3]*10+7);
			if(j>=4&&j-4!=1) dp[j]=min(dp[j],dp[j-4]*10+4);
			if(j>=5&&j-5!=1) dp[j]=min(dp[j],dp[j-5]*10+2);
			if(j>=6&&j-6!=1)
			{
				if(j<=7) dp[j]=min(dp[j],dp[j-6]*10+6);
				else dp[j]=min(dp[j],dp[j-6]*10);
			}
			if(j>=7&&j-7!=1) dp[j]=min(dp[j],dp[j-7]*10+8);
		}
		cout << dp[n] << endl;
	}
}
