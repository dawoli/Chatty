// Problem URL: https://www.luogu.com.cn/problem/P1525
// Finish Time: 2026/3/21 18:02:26 AC
// Finish Time: 2026/3/21 17:31:45 WA
// Start Time: 2026/3/21 17:09:29

#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int a,b,w;
}e[100005];
bool cmp(const Edge &x,const Edge &y)
{
	return x.w>y.w;
}
int n,m;
class dsu
{
	size_t dsz;
	vector<size_t> fa;
public:
	dsu(const size_t &n):dsz(2*n),fa(2*n+1)
	{
		for(int i=1;i<=dsz;i++) fa[i]=i;
	}
	dsu()=default;
	dsu &resize(const size_t &n)
	{
		return *this=dsu(2*n);
	}
	const size_t &find(const size_t &x)
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
		fa[y]=x;
		return true;
	}
	size_t size() const
	{
		return dsz;
	}
	size_t count() const
	{
		size_t cnt=0;
		for(int i=1;i<=dsz/2;i++) if(fa[i]==i) cnt++;
		return cnt;
	}
	bool friends(size_t x,size_t y)
	{
		if(query(x,y)) return false;
		merge(x,y);
		return true;
	}
	bool enimies(size_t x,size_t y)
	{
		if(query(x,y)) return false;
		merge(x,y+dsz/2);
		merge(y,x+dsz/2);
		return true;
	}
}d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	d.resize(n);
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].a>>e[i].b>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		int u=e[i].a;
		int v=e[i].b;
		int w=e[i].w;
		if(d.query(u,v))
		{
			cout<<w;return 0;
		}
		d.enimies(u,v);
	}
	cout<<0;
	return 0;
}