#include <bits/stdc++.h>

const int N = 1e5 + 5;

int r[N],c[N];
std::vector<int> S[N];

int main(){
	
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int T;
	
	for (std::cin >> T;T--;){
		
		int n,k,q;
		
		std::cin >> n >> k >> q;
		for (int i = 1;i <= n;i++){
			
			int l,tmp;
			
			std::cin >> l;
			S[i].clear();
			S[i].push_back(l);
			while (l--) std::cin >> tmp,S[i].push_back(tmp);
			
		}
		for (int i = 1;i <= q;i++){
			
			bool ok = false;
			
			std::cin >> r[i] >> c[i];
			if (r[i] == 1){
				
				for (int j = 1;!ok && j <= n;j++){
					
					int one_pos = -1;
					
					for (int K = 1;K <= S[j][0];K++){
				
						if (S[j][K] == 1) one_pos = K;
						if (S[j][K] == c[i] && one_pos != -1 && one_pos + k > K){ok = true;break;}
						
					}
					
				}
				
			}
			std::cout << ok << '\n';
			
		}
		
	}
	
	return 0;
}
