// Problem URL: https://www.luogu.com.cn/problem/P10108
// Finish Time: 2026/2/24 19:39:13 AC
// Finish Time: 2026/2/24 19:28:40 WA
// Start Time: 2026/2/24 19:13:54

// Categories: 动态规划
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,a[105],b[10005];
ll dp[10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0; i<m; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];
	for(int i=0; i<=n; i++) dp[i]=LLONG_MIN;
	dp[0]=0;
	ll ans=LLONG_MIN;
	for(int i=0; i<n; i++)
	{
		if(dp[i]==LLONG_MIN) continue;
		for(int j=0; j<m; j++)
		{
			int nxt=i+a[j];
			if(nxt<n)
			{
				dp[nxt]=max(dp[nxt],dp[i]+b[i]);
			}
			else
			{
				ans=max(ans,dp[i]+b[i]);
			}
		}
	}
	cout<<ans;
	return 0;
}