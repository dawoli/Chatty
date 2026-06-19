// Problem URL: https://www.luogu.com.cn/problem/P1892
// Finish Time: 2026/3/15 17:18:42 WA
// Start Time: 2026/3/15 16:52:11

// Categories: 数据结构-并查集
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	d.resize(n);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char op;
		cin>>op>>x>>y;
		if(op=='F') d.friends(x,y);
		else d.enimies(x,y);
	}
	cout<<d.count();
	return 0;
}