#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e6+5;
const int smal_maxn=1e4+5;
struct bian
{
	int u,v,w;
	bool operator<(bian another)const
	{
		return w<another.w; 
	}
}edge[maxn];

int n,m,k;
int fa[smal_maxn];
int ind[15];
int cun[smal_maxn];
int cnt;

int find(int u)
{
	if(fa[u]==0)
	{
		return u;
	}
	fa[u]=find(fa[u]);
	return fa[u];
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		int jian;
		cin>>jian;
		int ji=0;
		for(int u=1;u<=n;u++)
		{
			cin>>cun[u];
			if(cun[u]==0)
			{
				ji=u;
			}
		}
		for(int u=1;u<=n;u++)
		{
			edge[++cnt]={ji,u,cun[u]};
		}
	}
	sort(edge+1,edge+cnt+1);
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(edge[i].u)!=find(edge[i].v))
		{
			//cout<<"!!!"<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
			fa[find(edge[i].u)]=find(edge[i].v);
			ans+=edge[i].w;
		}
	}
	cout<<ans;
	return 0;
}
