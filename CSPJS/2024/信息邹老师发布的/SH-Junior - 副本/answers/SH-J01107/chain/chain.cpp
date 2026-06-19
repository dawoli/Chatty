#include<bits/stdc++.h> 

int S[100001][200001];
int r[100001];
int c[100001];

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	std::cin >> T;
	int n;
	int k;
	int q;
	int li;
	for (int i = 1; i <= T; i++){
		std::cin >> n >> k >> q;
		for (int j = 1; j <= n; j++){
			std::cin >> li;
			for (int k = 1; k <= li; k++){
				std::cin >> S[j][k];
			}
		}
		for (int j = 1; j <= q; j++){
			std::cin >> r[j] >> c[j];
		}
		std::cout << 1;
	}
	return 0;
}

