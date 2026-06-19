#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],tt[1000005],ans,dp[15][100000],cnt;
vector<pair<int,int> > q[1000005];
vector<int> a[15];
const int inf=0x3f3f3f3f;
int dis[1000005],st[1000005];
void dij(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=inf;st[i]=0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	dis[s]=0;
	Q.push({0,s});
	while(!Q.empty())
	{
		pair<int,int> t=Q.top();
		int b=t.second;
		Q.pop();
		for(int i=0;i<q[b].size();i++)
		{
			int u=q[b][i].first,w=q[b][i].second;
			if(st[u]==1) continue;
			st[u]=1;
			if(dis[u]>dis[b]+w)
			{
				dis[u]=dis[b]+w;
				Q.push({dis[u],u});
				ans+=w;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];tt[i]=1;cnt+=c[i];
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			cnt+=x;
			if(j!=1)
			a[i].push_back(x);
		}
	}
	if(cnt==0) 
	{
		cout<<0<<endl;return 0;
	}
	dij(1);
	cout<<ans<<endl;
	return 0;
}
