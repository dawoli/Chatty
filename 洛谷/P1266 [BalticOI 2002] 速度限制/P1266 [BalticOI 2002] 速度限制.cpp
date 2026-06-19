// Problem URL: https://www.luogu.com.cn/problem/P1266
// Finish Time: 2026/6/19 14:19:22 AC
// Start Time: 2026/6/19 10:10:43

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,d;
struct Edge
{
	int b,v,l;
};
vector<Edge> e[150];
double dis[150][501];
pair<int,int> pre[150][501];
bool vis[150][501];
struct Node
{
	int u,spd;
	double t;
	bool operator<(const Node &_b)const
	{
		return t>_b.t;
	}
};
void Dijkstra()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<=500;j++)
			dis[i][j]=1e18,vis[i][j]=false;
	dis[0][70]=0;
	priority_queue<Node> q;
	q.push({0,70,0});
	while(!q.empty())
	{
		Node cur=q.top();
		q.pop();
		int u=cur.u,spd=cur.spd;
		if(vis[u][spd])continue;
		vis[u][spd]=true;
		for(Edge &edge:e[u])
		{
			int v=edge.b;
			int ns=edge.v==0?spd:edge.v;
			double nt=dis[u][spd]+(double)edge.l/ns;
			if(nt<dis[v][ns]-1e-12)
			{
				dis[v][ns]=nt;
				pre[v][ns]={u,spd};
				q.push({v,ns,nt});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
	{
		int a,b,v,l;
		cin>>a>>b>>v>>l;
		e[a].push_back({b,v,l});
	}
	Dijkstra();
	int best_spd=0;
	for(int s=1;s<=500;s++)
		if(dis[d][s]<dis[d][best_spd])
			best_spd=s;
	vector<int> path;
	int cur=d,spd=best_spd;
	while(true)
	{
		path.push_back(cur);
		if(cur==0)break;
		auto p=pre[cur][spd];
		cur=p.first;
		spd=p.second;
	}
	reverse(path.begin(),path.end());
	for(size_t i=0;i<path.size();i++)
		cout<<path[i]<<" \n"[i==path.size()-1];
	return 0;
}