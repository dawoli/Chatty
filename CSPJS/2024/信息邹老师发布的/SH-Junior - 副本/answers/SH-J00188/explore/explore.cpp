#include<bits/stdc++.h>
using namespace std;
int t, n, m, k;
char g[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		int x, y, d, ans = 0, sum = 0, cnt = 0;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> g[i][j];
				if(g[i][j] == 'x') sum++;
			}
		}
		if(k == 1) {
			cout << 1 << endl;
			continue;
		}
		for(int i = 1; i <= k; i++){
			int tx = x + dx[d];
			int ty = y + dy[d];
			if(g[tx][ty] == '.' && tx >= 1 && tx <= n && ty >= 1 && ty <= m){
				x = tx;
				y = ty;
				g[tx][ty] = 'x';
			}else {
				d = (d + 1) % 4;
				g[x][y] = 'x';
			}
			//cout << x << " " << y << endl;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(g[i][j] == 'x') cnt++;
			}
		}
		ans = cnt - sum;
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
