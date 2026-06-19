// Problem URL: https:/www.luogu.com.cn/problem/P1551
// Finish Time: 2026/3/14 18:20:46 AC
// Finish Time: 2026/3/14 18:05:41 AC
// Start Time: 2026/3/14 17:54:46

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
	const size_t &find(const size_t &x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
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
}d(5000);
int n,m,p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>p;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		d.merge(x,y);
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<(d.find(x)==d.find(y)?"Yes":"No")<<'\n';
	}
	return 0;
}