#ifndef OI_TEMPLATES_DSU_HPP
#define OI_TEMPLATES_DSU_HPP
#include <vector>
#include <numeric>
#include <algorithm>

// DSU (并查集) Header-only 模板
struct DSU
{
	std::vector<int> p,r;
	DSU(int n=0) { init(n); }
	void init(int n) { p.resize(n+1); r.assign(n+1,0); std::iota(p.begin(),p.end(),0); }
	int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
	bool unite(int a,int b)
	{
		a=find(a); b=find(b);
		if(a==b) return false;
		if(r[a]<r[b]) std::swap(a,b);
		p[b]=a;
		if(r[a]==r[b]) r[a]++;
		return true;
	}
	bool same(int a,int b) { return find(a)==find(b); }
};

#endif // OI_TEMPLATES_DSU_HPP
