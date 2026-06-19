#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d;
char a[1005][1005];
bool vis[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	int cur = 0;
	while (t--){
		cur++;
		memset(a, ' ', sizeof(a));
		memset(vis, false, sizeof(vis));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		vis[x][y] = true;
		for (int i = 1; i <= k; i++){
			if (d == 0){
				if (a[x][y+1] != '.') d = (d + 1) % 4;
				else{
					y++;
					vis[x][y] = true;
				}
			}
			else if (d == 1){
				if (a[x+1][y] != '.') d = (d + 1) % 4;
				else{
					x++;
					vis[x][y] = true;
				}
			}
			else if (d == 2){
				if (a[x][y-1] != '.') d = (d + 1) % 4;
				else{
					y--;
					vis[x][y] = true;
				}
			}
			else{
				if (a[x-1][y] != '.') d = (d + 1) % 4;
				else{
					x--;
					vis[x][y] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (vis[i][j] == true) cnt++;
		cout << cnt << endl;
	}
	return 0;
}
