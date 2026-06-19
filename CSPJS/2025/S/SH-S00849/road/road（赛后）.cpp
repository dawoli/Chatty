#include<bits/stdc++.h>
using namespace std;
typedef size_t st;
struct dsu
{
	vector<st> fa,sz;
	dsu()=default;
	dsu(int nsz)
	{
		fa.resize(nsz+5);
		for(int i=0;i<=n;i++)
		{
			fa[i]=i;
		}
		sz.resize(nsz+5,1);
	}
	st find(st x)
	{
		return (fa[x]==x?x:fa[x]=find(x));
	}
	void merge(st x,st y)
	{
		x=find(x);
		y=find(y);
		if(sz[x]>sz[y])swap(x,y);
		fa[y]=x;
		sz[x]+=sz[y];
	}
};
struct edge
{
	int u,v,w;
}g[1100005];
int n,m,k,l=0,c[11],a[11][10005];
void add(int u,int v,int w)
{
	l++;
	g[l].u=u;
	g[l].v=v;
	g[l].w=w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
}