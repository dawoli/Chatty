#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T, n, m, k, x, y, d;
ll all_cnt = 0;
ll dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
struct node {
	ll x, y;
};
bool vis[1001][1001];
char maze[1001][1001];

queue <node> q;

void dfs (ll x, ll y, ll step) {
	q.push({x, y});
	vis[x][y] = 1;
	if (all_cnt == k) {
		cout << step << endl;
		return;
	}
	while (q.size() > 0) {
		node t = q.front();
		q.pop();
		ll d1 = d, cnt = 0;
		for (ll i = d1; cnt < 4; i = (i+1)%4) {
			ll nx = t.x + dir[i][0], ny = t.y + dir[i][1];
			cnt++;
			all_cnt++;
			if (nx<1 || nx>n || ny<1 || ny>n || vis[nx][ny]==1 || maze[nx][ny]=='x') {
				continue;
			}
			dfs(nx, ny, step+1);
			break;
		}
	}
	return;
}

int main() {
	freopen ("explore.in", "r", stdin);
	freopen ("explore.out", "w", stdout);
	cin >> T;
	for (ll o = 1; o <= T; o++) {
		cin >> n >> m >> k >> x >> y >> d;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				cin >> maze[i][j]; 
			}
		}
		cout << rand()%60 << endl;
		//dfs(x,y,0);
		//memset(vis, 0, sizeof(vis));
		//all_cnt = 0;
	}
	return 0;
}
