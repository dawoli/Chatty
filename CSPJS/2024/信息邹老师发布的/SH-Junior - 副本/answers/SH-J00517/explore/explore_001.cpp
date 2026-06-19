#include <iostream>
using namespace std;

int t;
char map[1005][1005];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n, m, k;
		int x, y, d;
//		cout << n << " " << m << " " << k << endl;
//		cout << x << " " << y << " " << d << endl; 
		scanf("%d%d%d", &n, &m, &k);
//		cin >> n >> m >> k;
		
		scanf("%d%d%d", &x, &y, &d);
//		cin >> x >> y >> d;
		
		for (int j = 1; j <= n; j++){
			for (int l = 1; l <= m; l++){
				cin >> map[j][l];
			}
		}
		
		map[x][y] = '#';
		for (int j	 = 1; j <= k; j++){
			
			int x0 = x, y0 = y, d0 = d;
			
			if (d == 0){
				y0 = y+1;
			} else if (d == 1){
				x0 = x+1;
			} else if (d == 2){
				y0 = y-1;
			} else {
				x0 = x-1;
			}
			
			if (1 <= x0 && n >= x0 && 1 <= y0 && m >= y0 && map[x0][y0] != 'x'){
				x = x0; y = y0; d = d0;	
			} else {
				d = (d0+1) % 4;
			}
			map[x][y] = '#';
		}
		
		int cnt = 0;
//		cout << i << endl;
		for (int j = 1; j <= n; j++){
			for (int l = 1; l <= m; l++){
				if (map[j][l] == (int)'#'){
					cnt++;
				}
				cout << (char)map[j][l];
			}
			cout << endl;
		}
		
		cout << cnt << endl;
		
	}
	
	return 0;
}
