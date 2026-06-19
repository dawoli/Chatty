#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int t, n, m, ans, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int d[1005][1005], vis[1005][1005];
char c[1005][1005];
void dfs(int x, int y, int cnt){
	if (x == n && y == m){
		return;
	}
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i], t = cnt;
		if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == '*'){
			continue;
		}
		if (c[nx][ny] == '$'){
			t++;
		}
		if (vis[nx][ny] > t){
			vis[nx][ny] = t;
			dfs(nx, ny, t);
		}
	}
}
struct node{
	int x, y, cnt;
	node(int a, int b, int c){
		x = a, y = b, cnt = c;
	}
	node(){
		
	}
};
queue <node> q;
void bfs(){
	vis[1][1] = 1;
	d[1][1] = 0;
	q.push(node(1, 1, 0));
	while (q.size()){
		node t = q.front();
		if (t.x == n && t.y == m){
			printf("%d\n", d[n][m]);
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = t.x + dx[i], ny = t.y + dy[i], ncnt = t.cnt;
			if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == '*'){
				continue;
			}
			if (c[nx][ny] == '$'){
				ncnt++;
			}
			if (ncnt > ans){
				continue;
			}
			if (!vis[nx][ny]){
				vis[nx][ny] = 1;
				d[nx][ny] = d[t.x][t.y] + 1;
				q.push(node(nx, ny, ncnt));
			}
		}
	}
}
int main()
{
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> c[i][j];
			}
		}
		memset(vis, 0x3f, sizeof vis);
		dfs(1, 1, 0);
		ans = vis[n][m];
		printf("%d ", ans);
		memset(vis, 0, sizeof vis);
		bfs();
	}
	return 0;
}

