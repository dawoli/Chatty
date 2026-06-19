#include <bits/stdc++.h>
using namespace std;
#include "../include/lca.hpp"

int main()
{
	LCA l(6);
	l.addEdge(1,2); l.addEdge(1,3); l.addEdge(2,4); l.addEdge(2,5); l.addEdge(3,6);
	l.build(1);
	if(l.lca(4,5)!=2) { cout<<"LCA: FAIL\n"; return 1; }
	if(l.lca(4,6)!=1) { cout<<"LCA: FAIL\n"; return 1; }
	cout<<"LCA: PASS\n";
	return 0;
}
