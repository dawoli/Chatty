#include <bits/stdc++.h>
using namespace std;
int t , n , m , k , x , y , d , i , j , a , ans;
char b [1000] [1000];
bool s () {return (x <= n && x >= 1) && (y <= m && y >= 1);}
int main () {
	freopen ("explore.in" , "r" , stdin);
	freopen ("explore.out" , "w" , stdout);
	cin >> t;
	for (a = 1;a <= t;a ++) {
		ans = 1;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (i = 1;i <= n;i ++) {
			for (j = 1;j <= m;j ++) {
				cin >> b [i] [j];
			}
		}
		for (i = 1;i <= n;i ++) {
			switch (d) {
				case 0 : {
					y ++;
					ans ++;
					if (s () || b [x] [y] == 'x') {
						y --;
						d = (d + 1) % 4;
						ans --;
					}
					break;
				}
				case 1 : {
					x ++;
					ans ++;
					if (s () || b [x] [y] == 'x') {
						x --;
						d = (d + 1) % 4;
						ans --;
					}
					break;
				}
				case 2 : {
					y --;
					ans ++;
					if (s () || b [x] [y] == 'x') {
						y ++;
						d = (d + 1) % 4;
						ans --;
					}
					break;
				}
				case 3 : {
					x --;
					ans ++;
					if (s () || b [x] [y] == 'x') {
						x ++;
						d = (d + 1) % 4;
						ans --;
					}
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
