#include <iostream>
#include <cstdio>
using namespace std;
int a[10][20] = {0};
int n;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		char s, t;
		cin >> s >> t;
		if(s == 'D'){
			if(t >= '0' && t <= '9'){
				a[1][t - '0'] = 1;
			}else if(t == 'T'){
				a[1][10] = 1;
			}else if(t == 'A'){
				a[1][1] = 1;
			}else if(t == 'J'){
				a[1][11] = 1;
			}else if(t == 'Q'){
				a[1][12] = 1;
			}else if(t == 'K'){
				a[1][13] = 1;
			}
		}else if(s == 'C'){
			if(t >= '0' && t <= '9'){
				a[2][t - '0'] = 1;
			}else if(t == 'T'){
				a[2][10] = 1;
			}else if(t == 'A'){
				a[2][1] = 1;
			}else if(t == 'J'){
				a[2][11] = 1;
			}else if(t == 'Q'){
				a[2][12] = 1;
			}else if(t == 'K'){
				a[2][13] = 1;
			}
		}else if(s == 'H'){
			if(t >= '0' && t <= '9'){
				a[3][t - '0'] = 1;
			}else if(t == 'T'){
				a[3][10] = 1;
			}else if(t == 'A'){
				a[3][1] = 1;
			}else if(t == 'J'){
				a[3][11] = 1;
			}else if(t == 'Q'){
				a[3][12] = 1;
			}else if(t == 'K'){
				a[3][13] = 1;
			}
		}else if(s == 'S'){
			if(t >= '0' && t <= '9'){
				a[4][t - '0'] = 1;
			}else if(t == 'T'){
				a[4][10] = 1;
			}else if(t == 'A'){
				a[4][1] = 1;
			}else if(t == 'J'){
				a[4][11] = 1;
			}else if(t == 'Q'){
				a[4][12] = 1;
			}else if(t == 'K'){
				a[4][13] = 1;
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 13; j++){
			if(a[i][j] == 0){
				ans++;
			}
		}
	} 
	
	cout << ans << endl;
	return 0;
}
