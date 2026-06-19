#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int n,m;
std::vector<int> a,c;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);	
	std::cin>>n>>m;
	a.reserve(n);
	for(int i=0,tmp;i<n;i++) {
		std::cin>>tmp;
		a.push_back(tmp);
	} 
	c.reserve(m);
	for(int i=0,tmp;i<m;i++) {
		std::cin>>tmp;
		c.push_back(tmp);
	}
	
	return 0;
}
