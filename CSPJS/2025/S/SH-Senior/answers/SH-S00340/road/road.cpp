#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct node{
	int t,v;
};
vector<node> g[10010];
int vc[15];
int vr[15][10010];
bool vis[10010];
int ans=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>vc[i];
		for(int j=1;j<=n;j++)
		{
			cin>>vr[i][j];
		}
	}
	priority_queue<pair<int,int > > q;
	for(auto p : g[1])
	{
		int v=p.v,t=p.t;
		q.push({-v,t});
	}
	vis[1]=1;
	int pts=1;
	while(!q.empty() && pts<n)
	{
		pts++;
		pair<int,int > p=q.top();
		q.pop();
		int v=-p.first;
		ans+=v;
		int to=p . second;
		vis[to]=1;
//		cout<<v<<' '<<to<<endl;
		for(auto d : g[to])
		{
			if(vis[d.t]) continue;
			q.push({-d.v , d.t});
		}
	}
	cout<<ans<<endl;
	return 0;
} 
