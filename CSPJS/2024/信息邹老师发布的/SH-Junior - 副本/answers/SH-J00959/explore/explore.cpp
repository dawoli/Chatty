#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
int x, y, d;
int main(){
	freopen("explore.in", "w", stdin);
	freopen("explore.out", "r", stdout);
	cin >> T;
	for (int a = 1; a <= T; a ++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		int v[n + 2][m + 2];
		int w[n + 2][m + 2];
		int ans = k + 1;
		for (int i = 0; i <= n + 1; i ++)
		    for (int j = 0; j <= m + 1; j ++)
		        w[i][j] = 0;
		for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= m; j ++){
				char s;
				cin >> s;
				if (s == "x") v[i][j] = 1;
				else v[i][j] = 0;
			}
		}
		for (int i = 1; i <= k; i ++){
			w[x][y] = 1;
			if (d == 0){
				if ((v[x][y + 1] == 1) || (y == m)){
					d = 1;
					ans --;
				}else if (w[x][y + 1] == 1){
					ans --;
					y ++;
				}else y ++;
			}if (d == 1){
				if ((v[x + 1][y] == 1) || (x == n)){
					d = 2;
					ans --;
				}else if (w[x + 1][y] == 1){
					ans --;
					x ++;
				}else x ++;				
			}if (d == 2){
				if ((v[x][y - 1] == 1) || (y == 1)){
					d = 3;
					ans --;
				}else if (w[x][y - 1] == 1){
					ans --;
					y --;
				}else y --;
			}if (d == 3){
				if ((v[x - 1][y] == 1) || (x == 1)){
					d = 0;
					ans --;
				}else if (w[x - 1][y] == 1){
					ans --;
					x --;
				}else x --;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
