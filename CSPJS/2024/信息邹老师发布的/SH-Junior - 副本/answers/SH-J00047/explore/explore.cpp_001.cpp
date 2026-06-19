#include<bits/stdc++.h>
using namespace std;
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
int t;
int n, m, k;
char c[1005][1005];
int x, y, d;
int ans = 0;
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};
int vis[1005][1005][5];
int vis2[1005][1005];
int flag;
void dfs(int x, int y, int d, int step){	
	if(vis2[x][y] == 0) ans++;
	vis2[x][y] = 1;
	if(step > k) {
		flag = 1;
		return;
	}
	if(flag == 1) return;
	int nx = x + dx[d], ny = y + dy[d];
	
	if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && c[nx][ny] == '.'){
		
		if(vis[nx][ny][d] == 0){
			vis[nx][ny][d] = 1;
			dfs(nx, ny, d, step + 1);
		
		}else return;
	}
	else{
		vis2[x][y] = 1;
		if(vis[x][y][(d+1) % 4] == 0){
			vis[x][y][(d + 1) % 4] = 1;
			dfs(x, y, (d + 1) % 4, step+1);
		}else return;
	
	}
	return;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--){
		memset(vis2, 0, sizeof(vis2));
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> c[i][j];
			}
		}
		ans = 1, flag = 0;
		vis2[x][y] = 1;
		vis[x][y][d] = 1;
		dfs(x, y, d, 1);
		cout << ans << endl;
	}
	
	return 0;
}
