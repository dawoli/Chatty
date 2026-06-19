// Problem URL: https://iai.sh.cn/problem/659
// Finish Time: 2026/5/16 17:50:34 AC
// Finish Time: 2026/5/16 17:42:33 WA 30pts
// Finish Time: 2026/5/16 17:37:18 WA
// Start Time: 2026/5/16 17:07:39

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int n,dp[25][5001],sum=0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	dp[0][0]=1;
	dp[1][1]=1;
	for(int k=2;k<=n;k++)
	{
		for(int l=0;l<k;l++)
		{
			int r=k-l-1;
			for(int lr=0;lr<25;lr++)
			{
				if(dp[lr][l]==0)continue;
				for(int rr=max(0LL,lr-1);rr<=min(24LL,lr+1);rr++)
				{
					if(dp[rr][r]==0)continue;
					int h=max(lr,rr)+1;
					dp[h][k]+=dp[lr][l]*dp[rr][r];
					dp[h][k]%=MOD;
				}
			}
		}
	}
	for(int i=0;i<25;i++)
	{
		sum+=dp[i][n];
		sum%=MOD;
	}
	cout<<sum;
	return 0;
}