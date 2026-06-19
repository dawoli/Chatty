#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fa[101010],sz[101010],max_size=1;
int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
void merge(int x,int y)
{
	int fx=findfa(x),fy=findfa(y);
	fa[fx]=fy;
	sz[fy]+=sz[fx],sz[fx]=0;
	max_size=max(max_size,sz[fy]);
}
struct edge{
	ll u,v,w;
}e[2020202];
ll n,m,k,c[11],a[11][10101];
void solve1()
{
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) m++,e[m].u=n+i,e[m].v=j,e[m].w=a[i][j];
	for(int i=1;i<=n;i++) sz[i]=1;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+1+m,[](edge x,edge y){
		return x.w<y.w;
	});
	int i=0;ll ans=0;
	while(max_size!=n)
	{
		i++;
		if(findfa(e[i].u)==findfa(e[i].v)) continue;
		merge(e[i].u,e[i].v);
		ans+=e[i].w;
	}
	cout<<ans<<endl;
}
void solve2()
{
	int mm=m;
	ll res=1e18;
	for(int state=0;state<(1<<k);state++)
	{
		m=mm;max_size=1;
		ll ans=0;
		for(int i=1;i<=k;i++)
		{
			if((state&(1<<(i-1)))==0) continue;
			ans+=c[i];
			for(int j=1;j<=n;j++) m++,e[m].u=n+i,e[m].v=j,e[m].w=a[i][j];
		}
		for(int i=1;i<=n;i++) sz[i]=1;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(e+1,e+1+m,[](edge x,edge y){
			return x.w<y.w;
		});
		int i=0;
		while(max_size!=n)
		{
			i++;
			if(findfa(e[i].u)==findfa(e[i].v)) continue;
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
		}
		res=min(res,ans);
	}
	cout<<res<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
		if(c[i]!=0) flag=0;
	}
	if(flag) solve1();
	else if(m<=100000&&k<=5) solve2();
	return 0;
}

