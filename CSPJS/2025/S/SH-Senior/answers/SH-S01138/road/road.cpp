#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> g[100010];//w,to
priority_queue<pii,vector<pii>,greater<pii>> pq;//dis,to
bool vis[100010];
int dis[100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	
	if (k>0){cout<<0<<endl;return 0;}
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u}); 
	}
	//0µ½1µÄÐéÄâ±ß 
	pq.push({0,1});
	int sum=0;
	while (pq.size())
	{
		pii top=pq.top();
		pq.pop();
		int d=top.first,x=top.second;
		if (vis[x])continue;
		vis[x]=1;
		sum+=d;
		for (pii tt:g[x])
		{
			pq.push(tt);
		}
	}
	cout<<sum<<endl;
}
