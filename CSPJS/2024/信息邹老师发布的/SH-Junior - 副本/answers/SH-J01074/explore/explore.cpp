#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define M 1005
ll T, n, m, k, x, y, d, ans;
char mp[M][M];
ll vis[M][M];
ll b[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d%d%d\n", &n, &m, &k);
		scanf("%d%d%d\n", &x, &y, &d);
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
				scanf("%c", &mp[i][j]);
				vis[i][j] = 0;
			}
			scanf("\n");
		}
		vis[x][y] = 1;
		ans++;
		while(k > 0){
			k--;
			ll nx = x + b[d][0], ny = y + b[d][1];
			if(nx <= n && nx >= 0 && ny <= m && ny >= 0 && mp[nx][ny] == '.'){
				x = nx, y = ny;
				if(!vis[x][y]) ans++;
				vis[x][y] = 1;
			}else{
				d = (d + 1) % 4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
