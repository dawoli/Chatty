#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E
{
	ll u,v,w;
	bool operator<(const E& T) const {return w<T.w;}
}e[(int)1e6+10],s[(int)1e4+10];
ll n,m,p,fa[(int)1e4+10],sum,c[15],a[15][(int)1e4+10],w[(int)1e3+10][(int)1e3+10];
ll find(ll k)
{
	if(k!=fa[k])fa[k]=find(fa[k]);
	return fa[k];
}
void kruskal(ll es)
{
	sort(e+1,e+1+es);
	for(ll i=1;i<=n;++i)fa[i]=i;
	ll cnt=0;
	for(ll i=1;i<=es&&cnt<n;++i)
	{
		ll x=find(e[i].u),y=find(e[i].v);
		if(x!=y)sum+=e[i].w,fa[y]=x,s[++cnt]=e[i];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&p);
	if(p==0)
	{
		for(ll i=1;i<=m;++i)scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
		kruskal(m),printf("%lld\n",sum),exit(0);
	}
	ll u,v,W,cnt=0,sumc=0;
	constexpr ll inf=1e15;
	for(ll i=1;i<=n;++i)fill(w[i]+1,w[i]+1+n,inf);
	for(ll i=1;i<=m;++i)scanf("%lld %lld %lld",&u,&v,&W),w[u][v]=w[v][u]=min(w[u][v],W);
	for(ll i=1;i<=p;++i)
	{
		scanf("%lld",c+i),sumc+=c[i];
		for(ll j=1;j<=n;++j)scanf("%lld",a[i]+j);
	}
	if(n<=1000)
	{
		if(sumc==0)
		{
			for(ll i=1;i<=p;++i)for(ll j=1;j<=n;++j)for(ll k=1;k<j;++k)w[j][k]=w[k][j]=min(w[j][k],a[i][j]+a[i][k]);
			for(ll i=1;i<=n;++i)for(ll j=1;j<i;++j)if(w[i][j]!=inf)e[++cnt]=(E){i,j,w[i][j]};
			kruskal(cnt),printf("%lld\n",sum),exit(0);
		}
	}
	return 0;
}

