#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1005][2000];
bool book[1005][2000];
bool res[100][2000];
int ask[2][1005]; 
int n, k, q;
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	
	while(t--){	
	memset(a, 0, sizeof a);
	memset(book, 0, sizeof book);
	memset(res, 0, sizeof res);
		int maxx = 0;
		cin >> n >> k >> q;
			for(int i = 1; i <= n; i++){
				cin >> a[i][0];
				for(int j = 1; j <= a[i][0]; j++){
					cin >> a[i][j];
					book[i][a[i][j]] = 1;
					maxx = max(maxx, a[i][j]); 
				}
			}
			int maax = 0;
			for(int i = 1; i <= q; i++){
				cin >> ask[0][i] >> ask[1][i];
				maax = max(maax, ask[0][i]);
			}
			int c, m;
			for(int j = 1; j <= n; j++){
				if(book[j][1]){
					for(int s = 1; s <= a[j][0]; s++){
						if(a[j][s]==1){
							for(int i = 1; i < k; i++){
								if(s+i<=a[j][0]) 
								res[1][a[j][s+i]] = 1;
							}
						}
					}
				}
			}
				for(int i = 2; i <= maax; i++){
					for(int j = 1; j <= maxx; j++){
						for(int f = 1; f <= n; f++){
							for(int e = 1; e <= a[f][0]; e++){
								if(a[f][e]==j){
									for(int g = 1; g < k; g++){
										if(e-g>0){
											res[i][j] = res[i-1][a[f][e-g]];
										}
									}
								}
							}
						}
					}
				}
				for(int i = 1; i <= q; i++){
					cout << res[ask[0][i]][ask[1][i]] << endl;
				}
			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
