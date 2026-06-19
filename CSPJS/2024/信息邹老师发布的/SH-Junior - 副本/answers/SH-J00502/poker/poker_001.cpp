#include <bits/stdc++.h>

int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int n;
	std::string s[55];
	
	std::cin >> n;
	for (int i = 1;i <= n;i++) std::cin >> s[i];
	std::sort(s + 1,s + 1 + n);
	int cnt = std::unique(s + 1,s + 1 + n) - 1 - s;
	std::cout << 52 - cnt << '\n';
	
	return 0;
}
