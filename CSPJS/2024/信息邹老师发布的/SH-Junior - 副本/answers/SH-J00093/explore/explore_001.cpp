#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool vis[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while (T --) {
		memset(vis,0,sizeof(vis));
		int n,m,k,x0,y0,d0;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= m;j ++) {
				cin >> c[i][j];
			}
		}
		vis[x0][y0] = 1;
		for (int i = 1;i <= k;i ++) {
			int fx = x0 + dx[d0],fy = y0 + dy[d0];
			if (fx < 1 || fx > n || fy < 1 || fy > n || c[fx][fy] == 'x') d0 = (d0 + 1) % 4;
			else {
				x0 = fx,y0 = fy;
				vis[x0][y0] = 1;
			}
		}
		int ans = 0;
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= m;j ++) {
				ans += vis[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
