#include <bits/stdc++.h>
using namespace std;
#include "../include/dsu.hpp"

int main()
{
	DSU d(5);
	d.unite(1,2);
	d.unite(3,4);
	if(!d.same(1,2)) { cout<<"DSU: FAIL\n"; return 1; }
	if(d.same(2,3)) { cout<<"DSU: FAIL\n"; return 1; }
	d.unite(2,3);
	if(!d.same(1,4)) { cout<<"DSU: FAIL\n"; return 1; }
	cout<<"DSU: PASS\n";
	return 0;
}
