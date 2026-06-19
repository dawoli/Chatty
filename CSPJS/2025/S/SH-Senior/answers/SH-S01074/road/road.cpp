#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10040;
const int M=2000006;
struct Edge
{
	int u,v;
	ll w;
};
int n,m,k,fa[N];
ll a[20][N],c[20],ans=0;
vector<pair<ll,ll>> e[N];
Edge edg[M];
bool cmp(const Edge &a,const Edge &b)
{
	return a.w<b.w;
}
int find(int u)
{
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
bool spj()
{
	for(int i=1;i<=k;i++)
	{
		if(c[i]!=0)return 0;
	}
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		edg[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		  cin>>a[i][j];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(edg+1,edg+1+m,cmp);
		int cnt=0;
		ans=0;
		for(int i=1;i<=m;i++)
		{
			int u=find(edg[i].u),v=find(edg[i].v);
			if(u==v)continue;
			fa[u]=v;
			cnt++;
			ans+=edg[i].w;
			if(cnt==n-1)break;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(spj())
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=k;i++)
		{
			fa[n+i]=n+i;
			for(int j=1;j<=n;j++)
				edg[++m]={n+i,j,a[i][j]};
		}
		sort(edg+1,edg+1+m,cmp);
		int cnt=0;
		ans=0;
		for(int i=1;i<=m;i++)
		{
			int u=find(edg[i].u),v=find(edg[i].v);
			if(u==v)continue;
			fa[u]=v;
			cnt++;
			ans+=edg[i].w;
			if(cnt==n+k-1)break;
		}
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		int kc,km,cnt;
		ll sum;
		ans=1e18;
		for(int P=0;P<(1<<k);P++)
		{
			for(int i=1;i<=n;i++)fa[i]=i;
			kc=0;
			km=m;
			sum=0;
			cnt=0;
			for(int t=1;t<=k;t++)
			{
				if((P>>(t-1))&1)
				{
					kc++;
					fa[n+kc]=n+kc;
					sum+=c[t];
					for(int i=1;i<=n;i++)
						edg[++km]={n+t,i,a[t][i]};
				}
			}
			sort(edg+1,edg+1+km,cmp);
			for(int i=1;i<=km;i++)
			{
				int u=find(edg[i].u),v=find(edg[i].v);
				if(u==v)continue;
				fa[u]=v;
				cnt++;
				sum+=edg[i].w;
				if(cnt==n+kc-1)break;
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}

