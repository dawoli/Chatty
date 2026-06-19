#include <bits/stdc++.h>
using namespace std;
/*
d为方向
0 = 左
1 = 下
2 = 右
3 = 上 
*/
int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 方向走位
int turn(int x){
	return (x + 1) % 4;
} // 旋转
int n, m, k; // n 为行数, m 为列数, k 为操作数
int ans, x, y, f;
char mp[1005][1005];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		cin >> x >> y >> f;
		for (int i = 1; i <= n; i++) cin >> mp[i] + 1;
		ans = 1;
		bool book[1005][1005];
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				book[i][j] = false;
			}
		}book[x][y] = true; 
		while (k > 0){
			while (mp[x][y] != 'x' && x >= 1 && y >= 1 && x <= n && y <= m && k > 0){
				x += dxy[f][0];
				y += dxy[f][1];
				k--;
				if (!book[x][y] && mp[x][y] != 'x' && x >= 1 && y >= 1 && x <= n && y <= n) ans++;
				book[x][y] = true;
			}
			x -= dxy[f][0];
			y -= dxy[f][1];
			f = turn(f);
			if (!book[x][y] && mp[x][y] != 'x' && x >= 1 && y >= 1 && x <= n && y <= n) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
