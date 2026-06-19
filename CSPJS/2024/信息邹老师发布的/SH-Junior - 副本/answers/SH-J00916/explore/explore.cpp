#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++){
		int n, m, k;
		cin >> n >> m >> k;
		char a[n + 1][m + 1];
		bool c[n + 1][m + 1];
		for(int j = 0 ; j <= n ; j++){
			for(int k = 0 ; k <= m ; k++){
				c[j][k] = 0;
			}
		}
		int x, y, d;
		cin >> x >> y >> d;
		for(int j = 1 ; j <= n ; j++){
			string l;
			cin >> l;
			for(int t = 1 ; t <= m ; t++){
				a[j][t] = l[t - 1];
			}
		}
		c[x][y] = 1;
		int cnt = 1;
		for(int j = 1 ; j <= k ; j++){
			c[x][y] = 1;
			int xx = x, yy = y;
			if(d == 0){
				yy++;
			}
			if(d == 1){
				xx++;
			}
			if(d == 2){
				yy--;
			}
			if(d == 3){
				xx--;
			}
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m){
				if(a[xx][yy] == '.'){
					x = xx;
					y = yy;
					if(c[x][y] == 0){
						cnt++;
					}
					continue;
				}
			}
			d = (d + 1) % 4;
			if(c[x][y] == 0){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
} 
