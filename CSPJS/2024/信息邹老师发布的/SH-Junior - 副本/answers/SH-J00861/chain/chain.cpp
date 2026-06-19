#include <bits/stdc++.h>

unsigned int t, n, k, q, l, r, c;
std::vector<std::vector<unsigned int>> s; 

int dfs(register unsigned int deepth = 0, register unsigned int last = 1){
	if(deepth == r){
		if(last == c){
			return 1;
		}
		return 0;
	}
	for(register unsigned int j = 0; j < n; j++){
		for(register unsigned int _i = 0; _i < s[j].size(); _i++){
			if(s[j][_i] == last){
				for(register unsigned int _k = 1; _k <= k; _k++){
					if(_i + k < s[j].size()){
						if(dfs(deepth + 1, s[j][_i + k]) == 1){
							return 1;
						}
					}
				}
			}
		}
	}
}

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	std::cin >> t;
	for(register unsigned int i = 0; i < t; i++){
		std::cin >> n >> k >> q;
		for(register unsigned int _i = 0; _i < n; _i++){
			std::cin >> l;
			s.push_back((std::vector<unsigned int>){});
			for(register unsigned int _j = 0; _j < l; _j++){
				s[_i].push_back(0);
				std::cin >> s[_i][_j];
			}
		}
		for(register unsigned short _i = 0; _i < q; _i++){
			std::cin >> r >> c;
			std::cout << dfs() << "\n";
		}
	}
	return 0;
}
