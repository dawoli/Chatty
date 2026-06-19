// Problem URL: https://www.luogu.com.cn/problem/P1396
// Finish Time: 2026/6/19 17:20:10 AC
// Start Time: 2026/6/19 17:07:07

#include <bits/stdc++.h>
#define w first
#define v second
#define pii pair<int,int>
using namespace std;
typedef long long int ll;
int n,m,s,t,mx[10004];
vector<pii > e[10004];
bitset<10004> vis;
priority_queue<pii,vector<pii>,greater<> > q;
pii tmp;
void Dijkstra()
{
	for(int i=1;i<=n;i++) mx[i]=INT_MAX;
	mx[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		int u=tmp.v;
		int w=tmp.w;
		if(vis[u])continue;
		vis[u]=true;
		for(auto i:e[u])
		{
			int v=i.v;
			int nw=max(w,i.w);
			if(nw<mx[v])
			{
				mx[v]=nw;
				q.push({mx[v],v});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
	}
	Dijkstra();
	cout<<mx[t];
	return 0;
}