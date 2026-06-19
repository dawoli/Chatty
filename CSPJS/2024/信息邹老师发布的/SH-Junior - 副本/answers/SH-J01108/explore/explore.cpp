#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, ans, daan[1005][1005] = {0};
char s[1005][1005];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n >> m >> k >> x >> y >> d;
		daan[x][y] = 1;
		for(int j = 1; j <= n; j++) {
			for(int q = 1; q <= m; q++) {
				cin >> s[j][q];
			}
		}
		for(int j = 1; j <= k; j++) {
			int jx, jy;
			if(d == 0) {
				jx = x;
				jy = y+1;
			}
			if(d == 1) {
				jx = x+1;
				jy = y;
			}
			if(d == 2) {
				jx = x;
				jy = y-1;
			}
			if(d == 3) {
				jx = x-1;
				jy = y;
			}
			if(1 <= jx && jx <= n && 1 <= jy && jy <= m && s[jx][jy] == '.') {
				x = jx;
				y = jy;
				daan[x][y] = 1;
			}else{
				d = (d+1)%4;
			}
		}
		for(int j = 1; j <= n; j++) {
			for(int q = 1; q <= m; q++) {
				if(daan[j][q] == 1) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
