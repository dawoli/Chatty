#include <bits/stdc++.h>
using namespace std;
#include "../include/bit.hpp"

int main()
{
	BIT b(5);
	b.add(1,5);
	b.add(3,2);
	if(b.sum(1)!=5) { cout<<"BIT: FAIL\n"; return 1; }
	if(b.sum(3)!=7) { cout<<"BIT: FAIL\n"; return 1; }
	if(b.range_sum(2,3)!=2) { cout<<"BIT: FAIL\n"; return 1; }
	cout<<"BIT: PASS\n";
	return 0;
}
