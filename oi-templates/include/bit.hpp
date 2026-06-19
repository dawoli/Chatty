#ifndef OI_TEMPLATES_BIT_HPP
#define OI_TEMPLATES_BIT_HPP
#include <vector>

// 树状数组 (Fenwick Tree) 1-indexed
struct BIT
{
	int n;
	std::vector<long long> t;
	BIT(int _n=0) { init(_n); }
	void init(int _n) { n=_n; t.assign(n+1,0); }
	void add(int i,long long v) { for(; i<=n; i+=i&-i) t[i]+=v; }
	long long sum(int i) { long long s=0; for(; i>0; i-=i&-i) s+=t[i]; return s; }
	long long range_sum(int l,int r) { if(r<l) return 0; return sum(r)-sum(l-1); }
};

#endif // OI_TEMPLATES_BIT_HPP
