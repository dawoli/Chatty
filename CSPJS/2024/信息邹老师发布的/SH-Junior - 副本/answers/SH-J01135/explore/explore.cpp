#include <bits/stdc++.h>
using namespace std;

bool c[1111][1111];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++){
		int n,m,k;
		int x,y,d;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		char map[1111][1111];
		for (int j = 1;j <= n;j++){
			for (int g = 1;g <= m;g++){
				cin >> map[j][g];
			}
		}
		
		int cnt = 1;
		for (int j = 1;j <= k;j++){
			if (d == 0){
				if (y+1 <= m && map[x][y+1] == '.') {
					y++;
					if (c[x][y] == 0) cnt++;
					c[x][y] = 1;
				}
				else d = (d+1)%4;
			} 
			else if (d == 1){
				if (x+1 <= n && map[x+1][y] == '.') {
					x++;
					if (c[x][y] == 0) cnt++;
					c[x][y] = 1;
				}
				else d = (d+1)%4;
			}
			else if (d == 2){
				if (y-1 >= 1 && map[x][y-1] == '.') {
					y--;
					if (c[x][y] == 0) cnt++;
					c[x][y] = 1;
				}
				else d = (d+1)%4;
			}
			else {
				if (x-1 >= 1 && map[x-1][y] == '.') {
					x--;
					if (c[x][y] == 0) cnt++;
					c[x][y] = 1;
				}
				else d = (d+1)%4;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
