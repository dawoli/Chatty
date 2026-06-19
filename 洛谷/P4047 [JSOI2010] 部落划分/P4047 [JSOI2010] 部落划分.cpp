// Problem URL: https://www.luogu.com.cn/problem/P4047
// Finish Time: 2026/3/28 19:11:03 AC
// Finish Time: 2026/3/28 19:06:53 WA
// Finish Time: 2026/3/28 18:29:45 WA
// Start Time: 2026/3/28 18:07:12

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
int n,k,t=0;
struct edge
{
	int u,v;
	double w;
	bool operator <(const edge &another) const
	{
		return w<another.w;
	}
};
struct point
{
	int x,y;
}p[1003];
double dist(const point &a,const point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
vector<edge> e;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	d.init(n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		p[++t]={x,y};
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e.push_back({i,j,dist(p[i],p[j])});
		}
	}
	sort(e.begin(),e.end());
	if(n==k)
	{
		cout<<fixed<<setprecision(2)<<e[0].w;
		return 0;
	}
	for(int i=0;i<e.size();i++)
	{
		//if(d.query(e[i].u,e[i].v)) continue;
		d.merge(e[i].u,e[i].v);
		if(d.count()==k)
		{
			while(1)
			{
				i++;
				if(!d.query(e[i].u,e[i].v))
				{
					cout<<fixed<<setprecision(2)<<e[i].w;
					break;
				}
			}
			return 0;
		}
	}
}