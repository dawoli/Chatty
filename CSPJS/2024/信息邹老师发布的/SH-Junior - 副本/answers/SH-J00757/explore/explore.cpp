#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		char a[1005][1005];
		bool p[1005][1005];
		int n, m, k, cnt = 0;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char c;
				cin >> c;
				a[i][j] = c;
				p[i][j] = false;
			}
		}
		p[x][y] = true;
		for(int i = 1; i <= k; i++){
			if(d == 0){
				if(x <= n && (y + 1) <= m && a[x][y + 1] == '.'){
					y++;
					p[x][y] = true;
				}
				else{
					d = (d + 1) % 4;
				}
			}
			else if(d == 1){
				if((x + 1) <= n && y <= m && a[x + 1][y] == '.'){
					x++;
					p[x][y] = true;
				}
				else{
					d = (d + 1) % 4;
				}
			}
			else if(d == 2){
				if(x <= n && (y - 1) <= m && a[x][y - 1] == '.'){
					y--;
					p[x][y] = true;
				}
				else{
					d = (d + 1) % 4;
				}
			}
			else if(d == 3){
				if((x - 1) <= n && y <= m && a[x - 1][y] == '.'){
					x--;
					p[x][y] = true;
				}
				else{
					d = (d + 1) % 4;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(p[i][j]){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
