#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define piii pair<ll,pair<ll,ll> >
ll n,m,k,c[15],vv=1,v=1,fa[100005],sz[100005],inf=1e17;
ll ans=inf,res,aa,bb;
piii pp[2000005],p[1000005];
bool gz[15];
ll find(ll x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void mg(ll x,ll y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x,y);
	fa[y]=x;
	sz[x]+=sz[y];
	sz[y]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&pp[vv].second.first,&pp[vv].second.second,&pp[vv].first);
		vv++;	
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&pp[vv].first);
			pp[vv].second.first=i+n;
			pp[vv].second.second=j;
			vv++;
		}
	}
	sort(pp+1,pp+vv);
	for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<vv;i++)
	{
		if(pp[i].second.first>n) p[v++]=pp[i];
		else
		{
			aa=pp[i].second.first,bb=pp[i].second.second;
			if(find(aa)==find(bb)) continue;
			p[v++]=pp[i];
			mg(aa,bb);
		}
	}
	for(ll tt=(1<<k)-1;tt>=0;tt--)
	{
		res=0;
		for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
		for(int i=0;i<k;i++)
		{
			if((tt>>i)&1) gz[i+1]=true,res+=c[i+1];
			else gz[i+1]=false;
		}
		for(int i=1;i<v;i++)
		{
			aa=pp[i].second.first,bb=pp[i].second.second;
			if(aa>n&&gz[aa-n]==false) continue;
			if(bb>n&&gz[bb-n]==false) continue;
			if(find(aa)==find(bb)) continue;
			res+=pp[i].first;
			if(res>ans) break;
			mg(aa,bb);
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
