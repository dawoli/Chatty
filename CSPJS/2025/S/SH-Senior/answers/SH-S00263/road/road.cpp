#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10,M=1e6+10,K=10;
const ll inf=1e15;
struct edge
{
	int u,v,w;
}pg[M],vl[N*K],g[M+N*K];
int ve[K][N],c[K],fa[N+K];
int n,m,k,tot,cnt,mxc;
ll ans=inf,tmp;
bool az[K],A=true;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void init()
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	tmp=0;
	tot=0;
}
void addver(int vi)
{
	for(int i=1;i<=n;i++)
	{
		tot++;
		vl[tot].u=n+vi+1;
		vl[tot].v=i;
		vl[tot].w=ve[vi][i];
	}
}
int mg()
{
	int i=1,j=1,x=1;
	while(i<=m&&j<=tot)
	{
		if(pg[i].w<=vl[j].w)
			g[x++]=pg[i++];
		else
			g[x++]=vl[j++];
	}
	while(i<=m)
		g[x++]=pg[i++];
	while(j<=tot)
		g[x++]=vl[j++];
	return x-1;
}
int findf(int x)
{
	if(x==fa[x])return x;
	fa[x]=findf(fa[x]);
	return fa[x];
}
void kruth()
{
	
}
void solveA()
{
	init();
	tot=m;
	for(int i=1;i<=m;i++)
		g[i]=pg[i];
	for(int i=0;i<k;i++)
	{
		int pos;
		for(int j=1;j<=n;j++)
			if(!ve[i][j])
			{
				pos=j;
				break;
			}
		for(int j=1;j<=n;j++)
		{
			tot++;
			g[tot].u=pos;
			g[tot].v=j;
			g[tot].w=ve[i][j];
		}
	}
	sort(g+1,g+tot+1,cmp);
	for(int j=1;j<=tot;j++)
	{
		int fu=findf(g[j].u),fv=findf(g[j].v);
		if(fu==fv)continue;
		tmp+=g[j].w;
		fa[fu]=fv;
	}
	cout<<tmp;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>pg[i].u>>pg[i].v>>pg[i].w;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		mxc=max(mxc,c[i]);
		for(int j=1;j<=n;j++)
		{
			cin>>ve[i][j];
			if(!ve[i][j])az[i]=true;
		}
		if(!az[i])A=false;
	}
	if(A&&!mxc)
	{
		solveA();
		return 0;
	}
	sort(pg+1,pg+m+1,cmp);
	for(int i=0;i<(1<<k);i++)
	{
		init();
		for(int j=0;j<k;j++)
			if(i>>j&1)
			{
				tmp+=c[j];
				addver(j);
			}
		sort(vl+1,vl+tot+1,cmp);
		cnt=mg();
		for(int j=1;j<=cnt;j++)
		{
			int fu=findf(g[j].u),fv=findf(g[j].v);
			if(fu==fv)continue;
			tmp+=g[j].w;
			fa[fu]=fv;
		}
		ans=min(ans,tmp);
	}
	cout<<ans;
	return 0;
}
