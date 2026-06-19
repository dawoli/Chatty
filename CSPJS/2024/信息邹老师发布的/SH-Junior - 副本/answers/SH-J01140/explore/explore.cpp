#include <cstdio>
#include <cstring>
using namespace std;

char g[1024][1024];
bool v[1024][1024];
int t, n, m, k, x, y, d, xx, yy, c, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main(){
	freopen("explore.in", "r", stdin), freopen("explore.out", "w", stdout), scanf("%d", &t);
	while (t--){
		memset(g, 0, sizeof(g)), memset(v, 0, sizeof(v)), c = 1, scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf(" %c", &g[i][j]);
		v[x][y] = 1;
		for (int i = 1; i <= k; i++) {
			xx = x + dx[d], yy = y + dy[d];
			if (g[xx][yy] == 120 || g[xx][yy] == 0) d = (d + 1) % 4;
			else{
				if (!v[xx][yy]) c++;
				x = xx, y = yy, v[x][y] = 1;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
