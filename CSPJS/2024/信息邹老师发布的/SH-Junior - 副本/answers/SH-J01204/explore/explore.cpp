#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, xx, yy, dd;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[1005][1005], vis2[1005][1005][4];
char ma[1005][1005];
int exp(int wx, int wy, int fx){
//	cout << "exp: " << "(" << wx << "," << wy << ")" << endl;
	int res = 0;
	if(vis2[wx][wy][fx] == 1){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(vis[i][j] == 1) res ++;
			}
		}
		return res;
	} 
	vis[wx][wy] = 1;
	vis2[wx][wy][fx] = 1;
	if(k == 0){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(vis[i][j] == 1) res ++;
			}
		}
		return res;
	}
	int nx = wx + dx[fx];
	int ny = wy + dy[fx];
//	cout << "     (" << nx << "," << ny << ")?" << endl;
	k --;
	if(ma[nx][ny] == '.') exp(nx, ny, fx);
	else if(ma[nx][ny] == 'x' || nx <= 0 || nx > n || ny <= 0 || ny > m){
		fx = (fx + 1) % 4;
		exp(wx, wy, fx);
	}
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i ++){
		cin >> n >> m >> k;
		cin >> xx >> yy >> dd;
		for(int j = 1; j <= n; j ++){
			for(int k = 1; k <= m; k ++){
				cin >> ma[j][k];
			}
		}
		vis[xx][yy] = 1;
		int ans = exp(xx, yy, dd);
		cout << ans << endl;
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
