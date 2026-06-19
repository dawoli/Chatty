#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,c[15],a[15][10005],sum,ans=1<<30;
ll dis[10025],f[10025],g[10025],fa[10025];
bool vis[10025];
struct edge
{
	ll to,w;
};
vector <edge> e[10025];
queue <ll> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	memset(dis,0x3f,sizeof(dis));
	memset(g,0x3f,sizeof(g));
	dis[1]=g[1]=0;
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		vis[u]=0;
		memset(f,0,sizeof(f));
		for(edge e:e[u]) f[e.to]=e.w;
		for(int i=1;i<=n;i++)
		{
			if(i==u) continue;
			ll w=1e18;
			for(int j=1;j<=k;j++)
				w=min(w,a[j][u]+a[j][i]+c[j]);
			if(f[i]) w=min(w,f[i]);
		//	printf("%lld -> %d: %lld\n",u,i,w);
			if(g[i]>w)
			{
			//	printf("%d: %lld %lld\n",i,w,g[i]);
				g[i]=w;
				
			//	q.push(i);
			//	vis[i]=1;
			}
			if(dis[i]>dis[u]+w&&!vis[i])
			{
			//	printf("%lld -> %d: %lld -> %lld\n",u,i,dis[i],dis[u]+w);
				dis[i]=dis[u]+w;
				q.push(i);
				vis[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) sum+=g[i];
	printf("%lld\n",sum);
	return 0;
}
