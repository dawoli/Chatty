#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int T,n,m,k;
char G[N][N];
bool vis[N][N];
bool check(int x,int y) {return x > 0 && x <= n && y > 0 && y <= m && G[x][y] == '.';}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		int x = 0, y = 0, d = 0, ans = 0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> G[i][j];
		vis[x][y] = 1;
		for (int r = 1; r <= k; r++) {
			int _x = x+dx[d], _y = y+dy[d];
			if (check(_x,_y)) {
				vis[_x][_y] = 1;
				x = _x;
				y = _y;
			} else d = (d+1)%4;
		}
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans += vis[i][j];
		printf("%d\n",ans);
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
