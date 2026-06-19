#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001;
const int maxm = 2001;
int word[maxn][maxm];
int T;
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	while(T--){
		int n, K, q;
		cin >> n >> K >> q;
		for(int i = 1; i <= n; i++){
			int l;
			cin >> l;
			word[i][0] = l;
			for(int j = 1; j <= l; j++){
				cin >> word[i][j];
			}
		}
		for(int i = 1; i <= q; i++){
			int r, c;
			cin >> r >> c;
			bool Find = false;
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= word[j][0]; k++){
					if(word[j][k] != 1)
						continue;
					for(int t = 1; t < K; t++){
						if(word[j][k + t] == c){
							Find = true;
							break;
						}
					}
					if(Find)
						break;
				}
				if(Find)
					break;
			}
			if(Find)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	
	return 0;
}
