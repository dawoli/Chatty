#include <iostream>
using namespace std;
int t;
char map[1005][1005];
int ans[1000006];
int n, m, k;
int x, y, d;
int x2, y2;
int main () {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int l = 1; l <= n; l++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[l][j];
			}
		}
		
		ans[i] = 1;
		for (int j = 1; j <= k; j++) {
//			cout << d;
			if(d == 0) {
				x2 = x;
				y2 = y + 1;
			}
			if(d == 1) {
				x2 = x + 1;
				y2 = y;
			}
			if(d == 2) {
				x2 = x;
				y2 = y - 1;
			}
			if(d == 3) {
				x2 = x - 1;
				y2 = y;
			}
			if((x2 <= n && y2 <= m) && (map[x2][y2] == '.')){
				x = x2;
				y = y2;
				if(map[x][y] == '.') {
					ans[i] ++;
				}
			}else {
				d = (d + 1) % 4;
			}
		}
		for (int l = 1; l <= n; l++) {
			for (int j = 1; j <= m; j++){
				map[l][j] = '0';
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
/*
1
1 5 4
1 1 2
....x

1
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

*/

