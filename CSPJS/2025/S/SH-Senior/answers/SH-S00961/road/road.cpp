#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
const ll N=1000005;
const ll INF=10000000000000000LL;
ll n,m,k,u,v,w;
ll head[N],to[N<<1],nxt[N<<1],c[N<<1],idx;
void add(ll u,ll v,ll w)
{
	to[++idx]=v,nxt[idx]=head[u],head[u]=idx,c[idx]=w;
}
ll co[20],a[11][10005],sum,ans=INF,dis[10100];
ll vis[20],cnt;
bool used[N];
void prim()
{
	for(int i=1;i<=n+k;++i) dis[i]=INF,used[i]=0;
	dis[1]=0;
	ll mn=INF,tmp;
	for(int i=1;i<=n+10;++i)
	{
		tmp=0;
		mn=INF;
		for(int j=1;j<=n;++j)
		   if(dis[j]<mn&&!used[j]) mn=dis[j],tmp=j;
		for(int j=1;j<=k;++j)
		   if(!used[j+n]&&vis[j]&&dis[j+n]<mn) mn=dis[j+n],tmp=j+n;
		if(!tmp) break;
		u=tmp;used[u]=1;
		sum+=dis[u];
		if(sum>=ans) break;
		if(u<=n)
		{
			for(int j=head[u];j;j=nxt[j])
			{
				if(used[to[j]]) continue;
				if(dis[to[j]]>c[j])
				{
					dis[to[j]]=c[j];
				}
			}
			for(int j=1;j<=k;++j)
			{
				if(!vis[j]||used[j+n]) continue;
				if(dis[j+n]>a[j][u])
				{
					dis[j+n]=a[j][u];
				}
			}
		}
		else
		{
			for(int j=1;j<=n;++j)
			{
				if(used[j]) continue;
				if(dis[j]>a[u-n][j])
				{
					dis[j]=a[u-n][j];
				}
			}
		}
	}
	ans=min(ans,sum);
}
int ok;
bool check()
{
	for(int i=1;i<=k;++i) if(!c[i]) return 0;
	for(int i=1;i<=k;++i)
	{
		ok=0;
		for(int j=1;j<=n;++j)
		   if(a[i][j]==0)
		   {
		   	ok=1;
		   	break;
		   }
		if(!ok) return 0;
	}
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i) u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	for(int i=1;i<=k;++i)
	{
		co[i]=read();
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	if(check())
	{
		sum=0;
		for(int i=1;i<=k;++i) vis[i]=1;
		prim();
		cout<<sum<<"\n";
		return 0;
	}
	for(int sta=0;sta<(1<<k);++sta)
	{
		sum=0;
		for(int i=1;i<=k;++i) vis[i]=(sta>>(i-1))&1;
		for(int i=1;i<=k;++i)
		   if(vis[i]) sum+=co[i];
		if(sum<ans) prim();
	}
	cout<<ans<<"\n";
	return 0;
}
