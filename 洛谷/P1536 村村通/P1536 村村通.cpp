// Problem URL: https://www.luogu.com.cn/problem/P1536
// Finish Time: 2026/3/14 18:27:48 AC
// Start Time: 2026/3/14 18:14:19

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
}d(1000);
int n,m,cnt=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(1)
	{
		cin>>n;
		if(n==0)return 0;
		cin>>m;
		d.init(n);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			d.merge(x,y);
		}
		cout<<d.count()-1<<'\n';
	}
	return 0;
}