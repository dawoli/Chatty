#include<bits/stdc++.h>
using namespace std;

int t, n, m, k, ans;
char c[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dfs(int step, int x, int y, int d){
	if (vis[x][y] == false){
		ans ++;
	}
	vis[x][y] = true;
	if (step >= k){
		cout << ans << endl;
		return;
	}
	for (int i = 1; i <= 4; i ++){
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (in(nx, ny) && c[nx][ny] == '.'){
			dfs(step+i, nx, ny, d);
			break;
		}else{
			d = (d+1)%4; 
		}
	}
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--){
		int sx, sy, sd;
		ans = 0;
		memset(c, sizeof(c), ' ');
		cin >> n >> m >> k;
		cin >> sx >> sy >> sd;
		for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= m; j ++){
				cin >> c[i][j];
				vis[i][j] = false;
			}
		}
		dfs(0, sx, sy, sd);
	}
}
