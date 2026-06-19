//100
#include<bits/stdc++.h>
using namespace std;

int T, n, m, k, sx, sy, sd, ans, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char c[1005][1005];
bool flag[1005][1005];
bool isnt(int x, int y){
	return x > n || x < 1 || y > m || y < 1 || c[x][y] == 'x';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> T;
	while(T --){
		memset(flag, 0, sizeof(flag));
		ans = 0;
		cin >> n >> m >> k >> sx >> sy >> sd;
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= m; ++ j)
				cin >> c[i][j];
		
		flag[sx][sy] = true;
		while(k --){
//			printf("sx = %d, sy = %d\n", sx, sy);
			if(isnt(sx + dir[sd][0], sy + dir[sd][1]))
				sd = (sd + 1) % 4;
			else
				sx += dir[sd][0], sy += dir[sd][1];
			flag[sx][sy] = true;
		}
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= m; ++ j)
				ans += flag[i][j];
		cout << ans << endl;
	}
	return 0;
}
