#include<bits/stdc++.h>
#define ll long long
#define pll pair<int,int>
using namespace std;

int n,m,k;
const int N=1e4+10,M=1e6+10;
struct info{
	int too;
	int vall;
	int f;
};
vector<info> g[N];
int c[N],fa[N];
int a[20][N];
int vis[20];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
}
struct node{
	int val;
	int now;
	int to;
	bool operator > (node x) const {
		return val > x.val;
	}
	bool operator < (node x) const {
		return val < x.val;
	}
};
priority_queue<node,vector<node>,greater<node> > pq;
ll ans=1e14;
ll nowans;

void solve()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			info Noww=g[i][j];
			if(vis[Noww.f]) 
			{
				pq.push({Noww.vall,i,Noww.too});
			}
		}
	}
	while(!pq.empty())
	{
		node k=pq.top();
		pq.pop();
		if(find(k.to)!=find(k.now))
		{
			nowans+=k.val;
			merge(k.now,k.to);
		}
	}
}

void dfs(int x,int asu)
{
	if(x==k+1)
	{
		nowans=asu;
		solve();
		ans=min(ans,nowans);
		return ;
	}
	vis[x]=1;
	dfs(x+1,asu+c[x]);
	vis[x]=0;
	dfs(x+1,asu);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road2.in","r",stdin);
	cin>>n>>m>>k;
	vis[0]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w,0});
		g[v].push_back({u,w,0});
	}
	bool flag=1;
	for(int ol=1;ol<=k;ol++)
	{
		cin>>c[ol];
		if(c[ol]!=0) flag=0;
		for(int ac=1;ac<=n;ac++)
		{
			cin>>a[ol][ac];
			if(a[ol][ac]!=0) flag=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				g[i].push_back({j,a[ol][i]+a[ol][j],ol});
			}
		}
	}
	if(flag)
	{
		solve();
		cout<<ans;
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
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
