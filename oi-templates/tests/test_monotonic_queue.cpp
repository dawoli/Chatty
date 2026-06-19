#include <bits/stdc++.h>
using namespace std;
#include "../include/monotonic_queue.hpp"

int main()
{
	vector<int> a={1,3,-1,-3,5,3,6,7};
	auto res=sliding_window_max(a,3);
	vector<int> expect={3,3,5,5,6,7};
	if(res!=expect) { cout<<"MonotonicQueue: FAIL\n"; return 1; }
	cout<<"MonotonicQueue: PASS\n";
	return 0;
}
