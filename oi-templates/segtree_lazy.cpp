#include <bits/stdc++.h>
using namespace std;

// 线段树（区间加，区间求和）模板，0-indexed接口示例
/*
 * 线段树（区间加，区间求和）模板，0-indexed 接口示例
 * 复杂度：每次操作 O(log n)，空间 O(n)
 * 用法示例：
 *   SegTree st(n);
 *   st.add(l, r, val); // [l, r)
 *   long long s = st.query(l, r);
 */
struct SegTree
{
	int n;
	vector<long long> sum,lz;
	SegTree(int _n=0) { init(_n); }
	void init(int _n) { n=1; while(n<_n) n<<=1; sum.assign(2*n,0); lz.assign(2*n,0); }
	void apply(int idx,int len,long long val) { sum[idx]+=val*len; lz[idx]+=val; }
	void push(int idx,int l,int r)
	{
		if(lz[idx]!=0&&l+1<r)
		{
			int m=(l+r)/2;
			apply(idx*2,m-l,lz[idx]);
			apply(idx*2+1,r-m,lz[idx]);
			lz[idx]=0;
		}
	}
	void pull(int idx) { sum[idx]=sum[idx*2]+sum[idx*2+1]; }
	void add(int L,int R,long long val) { add(L,R,val,1,0,n); }
	void add(int L,int R,long long val,int idx,int l,int r)
	{
		if(R<=l||r<=L) return;
		if(L<=l&&r<=R) { apply(idx,r-l,val); return; }
		push(idx,l,r);
		int m=(l+r)/2;
		add(L,R,val,idx*2,l,m);
		add(L,R,val,idx*2+1,m,r);
		pull(idx);
	}
	long long query(int L,int R) { return query(L,R,1,0,n); }
	long long query(int L,int R,int idx,int l,int r)
	{
		if(R<=l||r<=L) return 0;
		if(L<=l&&r<=R) return sum[idx];
		push(idx,l,r);
		int m=(l+r)/2;
		return query(L,R,idx*2,l,m)+query(L,R,idx*2+1,m,r);
	}
};
