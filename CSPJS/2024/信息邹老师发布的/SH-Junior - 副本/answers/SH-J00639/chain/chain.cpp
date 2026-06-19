#include<bits/stdc++.h>

using namespace std;

long long flag1, flag[1005];
int t, n, k, q, l, s[1005][200005], r, cc;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int p = 1; p <= t; p++){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++){
			cin >> l;
			for(int j = 1; j <= l; j++){
				cin >> s[i][j];
			}
		}
		for(int i = 1; i <= q; i++){
			cin >> r >> cc;
			flag1 = 0;
			for(int w = 1; w <= n; w++){
				for(int j = 1; j <= l; j++){
					if(s[w][j] == 1){
						flag[w]++;
					}
					if(s[w][j] == cc){
						flag1++;
						if(cc == 1){
							if(flag[w] > 1){
								cout << 1;
								return 0;
							}
						}else 
						if(flag[w] != 0){
							cout << 1;
							return 0;
						}
					}
				}
			}
			cout << 0;
		}
	}
	return 0;
} 
