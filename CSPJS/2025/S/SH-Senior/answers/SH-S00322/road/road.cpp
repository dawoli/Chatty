#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;

int n,m,k,u,v,w,c[K],a[K][N],fa[N+K];
bool us[K];
ll ans;
bool A=1;

struct edge{
	int u,v,w,c,alc;
}es[2*M];

bool cmp(edge p1,edge p2)
{
	return p1.w<p2.w;
}

void init()
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
}

int root(int p)
{
	if(p==fa[p]) return p;
	fa[p]=root(fa[p]);
	return fa[p];
}

void unite(int p1,int p2)
{
	fa[root(p2)]=fa[p1];
}

void kruscal()
{
	sort(es+1,es+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
	if(root(es[i].u)==root(es[i].v)) continue;
	ans+=es[i].w;
	unite(es[i].u,es[i].v);
	}
}

void kruscal_with_c()
{
	sort(es+1,es+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
	if(root(es[i].u)==root(es[i].v)) continue;
	us[es[i].c]=1;
	ans+=es[i].w;
	unite(es[i].u,es[i].v);
	}
}

int main()
	{
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge eg;
		eg.u=u,eg.v=v,eg.w=w,eg.c=0,eg.alc=0;
		es[i]=eg;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
		if(c[i]!=0) A=0;
	}
	init();
	if(A)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				m++;
				edge eg;
				eg.u=n+i,eg.v=j,eg.w=a[i][j],eg.c=0,eg.alc=0;
				es[m]=eg;
			}
		}
		kruscal();
		cout<<ans;
		return 0;
	}
	kruscal_with_c();
	cout<<ans;
	return 0;
	}
