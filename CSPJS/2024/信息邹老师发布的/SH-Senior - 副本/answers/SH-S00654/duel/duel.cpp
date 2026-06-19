#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    int n;
    std::cin >> n;
    std::vector<int> r(n);
    for(int &i:r) {
    	std::cin >> i;
	}
	std::sort(r.begin(),r.end());
	int cnt=0,now=r[0],ans=0;
	for(int &i:r) {
		if(i!=now){
			now=i;
			if (ans<cnt) ans=cnt;
			cnt=0;
		}
		cnt++;
	}
	if (ans<cnt) ans=cnt;
	std::cout << ans << '\n';
	
	return 0;
}
