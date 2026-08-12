// Problem URL: https://www.luogu.com.cn/problem/T766534?contestId=330334
// Start Time: 2026/6/21 13:05:40

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> t(n+1);
	for(int i=1;i<=n;++i)
	{
		int s;cin>>s;
		t[i].resize(s);
		for(int j=0;j<s;++j)
		{
			cin>>t[i][j];
		}
		sort(t[i].begin(),t[i].end());
	}
	vector<int> a(m+5);
	for(int i=1;i<=m;++i)
		cin>>a[i];
	vector<int> dp(m+5,INF);
	dp[0]=0;
	vector<int> mdp(n+5,INF);
	for(int i=1;i<=m;++i)
	{
		dp[i]=min(dp[i-1]+1,dp[i]);
		for(auto A:t[a[i]])
		{
			mdp[A]=min(mdp[A],dp[i-1]);
			if(i==m) dp[m]=min(dp[m],mdp[A]+1);
			else
			{
				bool can_nxt=binary_search(t[a[i+1]].begin(),t[a[i+1]].end(),A);
				if(can_nxt) dp[i]=min(dp[i],mdp[A]+1);
				else
				{
					if(binary_search(t[A].begin(),t[A].end(),a[i+1]))
					{
						dp[i]=min(dp[i],mdp[A]+1);
					}
					else
					{
						dp[i+1]=min(dp[i+1],mdp[A]+1);
					}
					mdp[A]=INF;
				}
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}