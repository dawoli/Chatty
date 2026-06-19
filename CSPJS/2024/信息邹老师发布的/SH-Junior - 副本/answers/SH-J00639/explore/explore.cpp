#include<bits/stdc++.h>

using namespace std;

int q, rn[2], sum;
int n, m, t, k, x, y, d;
char a[1005][1005];
int b[1005][1005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int p = 1; p <= t; p++){
		sum = 1;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		rn[0] = x;
		rn[1] = y;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
				b[i][j] = 0;
			}
		}
		b[x][y] = 1;
		for(int i = 1; i <= k; i++){
			if(d == 0){
				if((rn[1]+1 > m)||(a[rn[0]][rn[1]+1] == 'x')){
					d = (d+1)%4;
				}else{
					rn[1]++;
				}
			}
			else if(d == 1){
				if((rn[0]+1 > n)||(a[rn[0]+1][rn[1]] == 'x')){
					d = (d+1)%4;
				}else{
					rn[0]++;
				}
			}
			else if(d == 2){
				if((rn[1]-1 < 1)||(a[rn[0]][rn[1]-1] == 'x')){
					d = (d+1)%4;
				}else{
					rn[1]--;
				}
			}
			else if(d == 3){
				if((rn[0]-1 < 1)||(a[rn[0]-1][rn[1]] == 'x')){
					d = (d+1)%4;
				}else{
					rn[0]--;
				} 
			}
			if(b[rn[0]][rn[1]] == 0){
				b[rn[0]][rn[1]] = 1;
				sum++;
//				cout << rn[0] << " " << rn[1] << endl;
			}
		}
		cout << sum << endl;
	}
	return 0;
} 
