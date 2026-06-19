#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,w;
	bool operator<(const node x) const
	{
		return x.w<w;
	}
};
int n,m,k,dis[10010],ans,cnt=1;
vector<node> edges[10010];
void solve()
{
	priority_queue<node> pq;
	dis[1]=1;
	for(auto x:edges[1]) pq.push(x);
	while(!pq.empty()&&cnt!=n)
	{
		auto t=pq.top();
		pq.pop();
		if(dis[t.v]!=0) continue;
		dis[t.v]=1;
		cnt++;
		ans+=t.w;
		for(auto x:edges[t.v]) pq.push(x);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=n;i++)
	{
		cin>>u>>v>>w;
		edges[u].push_back({v,w});
		edges[v].push_back({u,w});
	}
	solve();
	cout<<ans;
}
