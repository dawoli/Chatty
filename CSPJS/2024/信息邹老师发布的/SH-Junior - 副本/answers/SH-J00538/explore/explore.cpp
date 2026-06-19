#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, ans = 0;
char mp[1005][1005];
bool vis[1005][1005] = {false};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool is_valid(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != 'x';}

void dfs(int step, int x, int y, int op){
	if(step == k+1) return;
	vis[x][y] = true;
	int nx = x + dx[op];
	int ny = y + dy[op];
	if(is_valid(nx, ny)){
		if(!vis[nx][ny]) ans++;
		dfs(step+1, nx, ny, op);
	}
	else dfs(step+1, x, y, (op+1)%4);
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x, &y, &d);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> mp[i][j];
		memset(vis, false, sizeof(vis));
		ans = 1;
		dfs(1, x, y, d);
		printf("%d\n", ans);
	}
	return 0;
}
