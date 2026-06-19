#include <bits/stdc++.h>
// #define debugging
using namespace std;
int n,m,ans=INT_MIN;
int arr[200010][3];
int vis[200100];
class ProvedSolution
{
	public:
	void dfs(map<int,vector<int>> distribution,int notdistributed,int happiness)
	{
		if(distribution[0].size()>n/2||distribution[1].size()>n/2||distribution[2].size()>n/2||notdistributed<0) return;
		if(notdistributed==0) {ans=max(ans,happiness);return;}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			for(int j=0;j<3;j++)
			{
				vis[i]=1;
				distribution[j].push_back(i);
				dfs(distribution,notdistributed-1,happiness+arr[i][j]);
				distribution[j].pop_back();
				vis[i]=0;
			}
		}
	}
	void entry()
	{
		dfs({},n,0);
	}
};
class Solution
{
	void entry()
	{
		
	}
};
void init()
{
	memset(arr,0,sizeof arr);
	memset(vis,0,sizeof vis);
	ans=INT_MIN;
}
void solve()
{
	init();
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin>>arr[i][j];
	ProvedSolution().entry();
	cout<<ans<<endl;
}
int main()
{
	#ifndef debugging
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	#ifdef singletest
	solve();
	#else
	int z;
	cin>>z;
	while(z--) solve();
	#endif
}
