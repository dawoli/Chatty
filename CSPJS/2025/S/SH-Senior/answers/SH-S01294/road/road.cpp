#include <bits/stdc++.h>
#define singletest
// #define debugging
using namespace std;
int ans=0;int n,m,k;
struct motorways
{
	int from,to,cost;
};
vector<motorways> graph;
vector<vector<pair<int,int>>> yagraph;
struct cityify
{
	int cost;
	int linking[20010];
}arr[20010];
class Solution
{
	public:
	int p[100010];
	Solution()
	{
		for(int i=1;i<=100010;i++) p[i]=i;
	}
	static bool cmp(motorways a,motorways b)
	{
		return a.cost<b.cost;
	}
	void graphbuilding()
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					graph.push_back({i,j,arr[i].linking[j]+arr[i].linking[k]+arr[i].cost});
					graph.push_back({j,i,arr[i].linking[j]+arr[i].linking[k]+arr[i].cost});
				}
			}
		}
		sort(graph.begin(),graph.end(),cmp);
	}
	bool IsConnected(int a,int b)
	{
		/*
		 @brief 并查集，感觉也错了 
		 */
		if(p[a]==b||p[b]==a) return 1;
		//cout<<a;
		return IsConnected(p[a],b);
	}
	void kruskal()
	{
		/*
		 @brief 这个应该错了...循环实现的 kruskal
		 */
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(!IsConnected(i,j))
				{
					ans++;
					p[i]=j;
				}
			}
		}
	}
	void entry()
	{
		graphbuilding();
		kruskal();
	}
};
class YetAnotherSolution
{
	/*
	 @brief 这个不是大概，是肯定错了 (floyd 联通的是最短路，不保证整张图都联通，结果我猜会偏小)
	 */
	 public:
	 int dp[10001][10001];
	 static bool cmp(motorways a,motorways b)
	{
		return a.cost<b.cost;
	}
	 void graphbuilding()
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					yagraph[i].push_back({j,arr[i].linking[j]+arr[i].linking[k]+arr[i].cost});
					yagraph[j].push_back({i,arr[i].linking[j]+arr[i].linking[k]+arr[i].cost});
				}
			}
		}
		sort(graph.begin(),graph.end(),cmp);
	}
	int floyd()
	{
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
		int maxx=INT_MIN;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) maxx=max(maxx,dp[i][j]);
		return maxx;
	}
	void entry()
	{
		graphbuilding();
		floyd();
	}
};
void init()
{
	
}
void solve()
{
	init();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		graph.push_back({a,b,c});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>arr[i].cost;
		for(int j=1;j<=n;j++) cin>>arr[i].linking[j]; 
	}
	if(n<=1000) YetAnotherSolution().entry();
	else Solution().entry():
	cout<<ans;
}
int main()
{
	#ifndef debugging
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
}
