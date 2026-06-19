#include<bits/stdc++.h>
using namespace std;
struct Node
{
	long long to,weight;
	bool operator<(const Node& x)const
	{
		return weight>x.weight;
	}
};
int n,m,k;
vector<Node>g[10005];
bool b[10005];
int c[15];
int a[15][10005];
priority_queue<Node>pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<g[1].size();i++)
	{
		pq.push(g[1][i]);
	}
	b[1]=true;
	long long ans=0;
	while(!pq.empty())
	{
		Node t=pq.top();
		pq.pop();
		if(b[t.to])continue;
		b[t.to]=true;
		ans+=t.weight;
		for(int i=0;i<g[t.to].size();i++)
		{
			if(!b[g[t.to][i].to])pq.push(g[t.to][i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
