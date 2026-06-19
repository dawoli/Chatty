#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int n,m,k;
int a[N],v[N];
int dis[N],vis[N];
struct Node
{
	int to,w;
};
queue<pair<int,int>>q;
vector<Node>edge[N];
int dj(int st,int ed)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for(int i=1;i<=n+k;i++)
	{
		dis[i]=0x3f3f3f3f;
		vis[N]=false;
	}
	dis[st]=0;
	pq.push({0,st});
	while(!pq.empty())
	{
		pair<int,int>t=pq.top();
		int v=t.second;
		pq.pop();
		if(vis[v])continue;
		vis[v]=true;
		for(const Node& e : edge[v])
		{
			int to=e.to,w=e.w;
			if(dis[to]>dis[v]+w)
			{
				dis[to]=dis[v]+w;
				q.push({to,v});
				pq.push({dis[to],to});
			}
		}
	}
	return dis[ed];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,w;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		edge[x].push_back({y,w});
		edge[y].push_back({x,w});
		p.push({w,y});
	}
//	cout<<x<<endl;

	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			cin>>v[i];
			edge[i+n].push_back({j,v[i]});
			edge[j].push_back({i+n,v[i]});
			p.push({v[i],i+n});
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		pair<int,int>t=p.top();
		ans+=t.first;
		if(t.second>n)
		{
			ans+=a[t.second-n];
		}
		q.pop();
	}
	cout<<ans;
//	if(k==0)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(dj)
//		}
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
