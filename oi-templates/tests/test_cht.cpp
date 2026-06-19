#include <bits/stdc++.h>
using namespace std;
#include "../include/cht.hpp"

int main()
{
	CHT cht;
	cht.add(3,0); // y = 3x
	cht.add(1,5); // y = x+5
	long long v0=cht.query(0); // max at x=0
	long long v1=cht.query(2);
	if(v0!=5&&v0!=0) { cout<<"CHT: FAIL\n"; return 1; }
	// basic sanity: should produce finite numbers
	cout<<"CHT: PASS\n";
	return 0;
}
