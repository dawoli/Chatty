#include <bits/stdc++.h>
using namespace std;
#include "../include/segtree_lazy.hpp"

int main()
{
	SegTree st(8);
	st.add(0,4,1); // add 1 to [0,4)
	st.add(2,6,2); // add 2 to [2,6)
	if(st.query(0,2)!=2) { cout<<"SegTree: FAIL\n"; return 1; }
	if(st.query(2,3)!=3) { cout<<"SegTree: FAIL\n"; return 1; }
	cout<<"SegTree: PASS\n";
	return 0;
}
