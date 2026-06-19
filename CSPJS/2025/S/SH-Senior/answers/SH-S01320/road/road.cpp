#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct E{int u,v,w;}e[M],ee[M];
int fa[N<<1],c[15];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,[](E a,E b){return a.w<b.w;});
	iota(fa+1,fa+n+1,1);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)
		{
			fa[u]=v;
			ans+=e[i].w;
			ee[++cnt]=e[i];
		}
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int a;cin>>a;
			ee[++cnt]={j,n+1+i,a};
		}
	}
	sort(ee+1,ee+cnt+1,[](E a,E b){return a.w<b.w;});
	for(int i=0;i<1<<k;i++)
	{
		int ss=0;
		for(int j=0;j<k;j++)if(i&(1<<j))ss+=c[j];
		iota(fa+1,fa+n+k+1,1);
		for(int j=1;j<=cnt;j++)
		{
			int v=ee[j].v;
			if(v<=n||(i&(1<<v-n-1)))
			{
				int u=find(ee[j].u);
				v=find(v);
				if(u!=v)
				{
					fa[u]=v,ss+=ee[j].w;
				}
			}
		}
		ans=min(ans,ss);
	}
	cout<<ans;
}
