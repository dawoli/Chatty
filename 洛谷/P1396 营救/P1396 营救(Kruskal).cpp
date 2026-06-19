// Problem URL: https://www.luogu.com.cn/problem/P1396
// Finish Time: 2026/6/19 16:52:57 AC
// Start Time: 2026/6/19 16:39:11

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class dsu
{
	size_t dsz;
	vector<size_t> fa,sz;
public:
	dsu(const size_t &n):dsz(n),fa(n+1),sz(n+1,1)
	{
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	dsu()=default;
	dsu &init(const size_t &n)
	{
		return *this=dsu(n);
	}
	size_t find(const size_t &x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool query(const size_t &x,const size_t &y)
	{
		return find(x)==find(y);
	}
	bool merge(size_t x,size_t y)
	{
		x=find(x),y=find(y);
		if(x==y) return false;
		if(sz[x]<sz[y]) swap(x,y);
		fa[y]=x,sz[x]+=sz[y];
		return true;
	}
	size_t size() const
	{
		return dsz;
	}
	size_t size(const size_t &x)
	{
		return sz[find(x)];
	}
	size_t count()
	{
		size_t cnt=0;
		for(int i=1;i<=dsz;i++) if(fa[i]==i) cnt++;
		return cnt;
	}
}d;
struct Edge
{
	int u,v,w;
	bool operator<(const Edge &_b)const
	{
		return w<_b.w;
	}
}e[2*10000+1];
int n,m,s,t,mx=INT_MIN;
void Kruskal()
{
	sort(e+1,e+m+1);
	d.init(n);
	for(int i=1;i<=m;i++)
	{
		int &u=e[i].u,&v=e[i].v,&w=e[i].w;
		if(d.merge(u,v))
		{
			mx=max(mx,w);
			if(d.query(s,t))return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	Kruskal();
	cout<<mx;
	return 0;
}