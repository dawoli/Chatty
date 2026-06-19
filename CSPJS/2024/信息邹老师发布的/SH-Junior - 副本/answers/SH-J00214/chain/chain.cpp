#include<bits/stdc++.h>
using namespace std;

int T;

int n, k, q;
int r, c;

int s[1005][2005];

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	
	cin >> T;
	
	while(T--){
		cin >> n >> k >> q;
		
		for(int i = 1;i <= n;i++){
			cin >> s[i][1];
			
			for(int j = 2;j <= s[i][1] + 1;j++) cin >> s[i][j];
		}
		
		while(q--){
			cin >> r >> c;
			bool ans = 0;
				
			for(int i = 1;i <= n;i++){
				for(int j = 2;j <= s[i][1] + 1;j++){
					if(s[i][j] == 1){
						for(int p = 1;p < k;p++){
							if(j + p > s[i][1] + 1) break;
							
							if(s[i][j + p] == c){
								cout << 1 << endl;
								ans = 1;
								
								break;
							}
						}
					}
					
					if(ans) break;
				}
				
				if(ans) break;
			}
			
			if(!ans) cout << 0 << endl;
		}
	}
	return 0;
}
