#include <bits/stdc++.h>
using namespace std;

// 树状数组 (Fenwick Tree) 模板：1-indexed，点加与前缀和
/*
 * 树状数组 (Fenwick Tree) 模板：1-indexed，点加与前缀和
 * 复杂度：单次 add/sum O(log n)，空间 O(n)
 * 用法示例：
 *   BIT b(n);
 *   b.add(i, val);
 *   long long pref = b.sum(i);
 */
struct BIT
{
	int n;
	vector<long long> t;
	BIT(int _n=0) { init(_n); }
	void init(int _n) { n=_n; t.assign(n+1,0); }
	void add(int i,long long v) { for(; i<=n; i+=i&-i) t[i]+=v; }
	long long sum(int i) { long long s=0; for(; i>0; i-=i&-i) s+=t[i]; return s; }
	long long range_sum(int l,int r) { if(r<l) return 0; return sum(r)-sum(l-1); }
};
