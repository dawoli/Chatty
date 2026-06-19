// Problem URL: https://www.luogu.com.cn/problem/P1266
// Start Time: 2026/6/19 10:10:43

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,d,dis[150],pre[150];
bitset<150> vis;
/*
int speed(const int &u)
{
	if(!spd[u])return spd[u];
	return speed(pre[u]);
}
*/
struct Road
{
	int b,v,l;
	double len(const int &vold)const
	{
		return (double)l/speed(vold);
	}
	int speed(const int &vold)const
	{
		if(v!=0)return v;
		return vold;
	}
};
vector<Road> e[150];
struct Node
{
	int v,w,spd;
	bool operator<(const Node &_b)const
	{
		return w>_b.w;
	}
}tmp;
priority_queue<Node> q;
void Dijkstra()
{
	for(int i=0;i<n;i++)dis[i]=INT_MAX;
	//for(int i=0;i<n;i++)pre[i]=0;
	dis[0]=0;
	pre[0]=INT_MIN;
	tmp.v=0,tmp.w=0,tmp.spd=70;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		int u=tmp.v;
		int spd=tmp.spd;
		if(vis[u])continue;
		vis[u]=true;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].b;
			//if(vis[v])continue;
			double len=e[u][i].len(spd);
			if(dis[u]+len<dis[v]/*&&fabs(dis[u]+len-dis[v]>1e-6)*/)
			{
				dis[v]=dis[u]+len;
				pre[v]=u;
			}
			tmp.v=v,tmp.w=dis[v],tmp.spd=e[u][i].speed(spd);
			q.push(tmp);
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
	vector<int> path;
	for(int i=d;i!=INT_MIN;i=pre[i])
		path.push_back(i);
	reverse(path.begin(),path.end());
	for(int i=0;i<path.size();i++)
	{
		cout<<path[i]<<' ';
	}
	return 0;
}
/*
6 15 1
0 1 25 68
0 2 30 50
0 5 0 101
1 2 70 77
1 3 35 42
2 0 0 22
2 1 40 86
2 3 0 23
2 4 45 40
3 1 64 14
3 5 0 23
4 1 95 8
5 1 0 84
5 2 90 64
5 3 36 40
*/