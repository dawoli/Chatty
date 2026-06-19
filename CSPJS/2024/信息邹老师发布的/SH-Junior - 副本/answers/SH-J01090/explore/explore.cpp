#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1010;
int d1[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n, m, k, x, y, d;
char ex_map[MAXN][MAXN];
bool vis[MAXN][MAXN]; 

bool is_ok(int x, int y) {
	return (x >= 1 && x <= n) && (y >= 1 && y <= m) && ex_map[x][y] == '.';
}

void solve() {
	// 1<=T<=5, 1<=n,m<=1000, 1<=k<=1000000
	int ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d", &x, &y, &d);
	memset(vis, 0, sizeof(vis));
	for (int i=1;i<=n;i++) {
		scanf("%s", ex_map[i]+1); 
	}
	for (int i=1;i<=k;i++) {
		if (!vis[x][y]) {
			vis[x][y] = true;
			ans++;
		}
		int xc = x + d1[d][0];
		int yc = y + d1[d][1];
		if (is_ok(xc,yc)) {
			x = xc;
			y = yc;
		} else {
			// ÏòÓÒ×ª
			d = (d+1)%4; 
		}
	}
	if (!vis[x][y]) {
		vis[x][y] = true;
		ans++;
	}
	printf("%d\n", ans);
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
	
	return 0;
} 
