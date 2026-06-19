#include<bits/stdc++.h>
using namespace std;

/*
Plan A: Ä£Äâ
O(t*k) = 5*1e6 ¿ÉÐÐ (°¡£¿) 
*/

int fx[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int t, n, m, k, xs, ys, ds;
char g[1001][1001];
int cnt, xx, yy;
int v[1001][1001];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		cin >> xs >> ys >> ds;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				cin >> g[i][j];
				v[i][j] = 0;
			}
		}
		
		v[xs][ys] = 1;
		cnt = 1;
		for (int _=0; _<k; _++) {
			xx = xs + fx[ds][0];
			yy = ys + fx[ds][1];
			
			if ((1<=xx && xx<=n && 1<=yy && yy<=m) && g[xx][yy]=='.') {
				xs = xx;
				ys = yy;
				
				if (!v[xs][ys]) cnt++;
				v[xs][ys] = 1;
			} else {
				ds = (ds+1)%4;
			}
		}
		
		cout << cnt << '\n'; 
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

