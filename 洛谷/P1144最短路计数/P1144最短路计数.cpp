#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
	int n,m,dis[1000001],cnt[1000001];
	const int mod=100003;
	vector<vector<int>> e;
	priority_queue<int,vector<int>,less<int>> q;
	void Dijkstra()
	{
		q.push(1);
		while(!q.empty())
		{
			int u=q.top();
			q.pop();
			for(int i=0;i<e[u].size();i++)
			{
				int v=e[u][i];
				if(dis[v]>dis[u]+1)
				{
					cnt[u]=1;
					dis[v]=dis[u]+1;
				}
				else if(dis[v]==dis[u]+1)
				{
					cnt[u]++;
					if(cnt[u]>mod)cnt[u]-=mod;
				}
				q.push(v);
			}
		}
	}
	void Soar()
	{
		cin>>n>>m;
		memset(dis,217,sizeof(dis));
		dis[1]=0;
		memset(cnt,0,sizeof(cnt));
		cnt[1]=1;
		e.resize(n+1,vector<int>());
		for(int i=1;i<=m;i++)
		{
			int x,y;
			bool flag1=1,flag2=1;
			cin>>x>>y;
			for(int i=0;i<e[x].size();i++)
			{
				if(e[x][i]==y)
				{
					flag1=0;
					break;
				}
			}
			for(int i=0;i<e[y].size();i++)
			{
				if(e[y][i]==x)
				{
					flag2=0;
					break;
				}
			}	
			if(flag1)e[x].push_back(y);
			if(flag2)e[y].push_back(x);		
		}
		cerr<<"Input Fine"<<endl;
		Dijkstra();
		for(int i=1;i<=n;i++)
		{
			cout<<cnt[i]<<endl;
		}
	}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}