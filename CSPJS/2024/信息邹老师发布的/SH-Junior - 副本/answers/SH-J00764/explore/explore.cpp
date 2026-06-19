#include <bits/stdc++.h>
using namespace std;
int n, m, k, q, x, y, d, ans=0;
char a[1010][1010];
bool vis[1010][1010];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> q;
	while(q--){
		ans = 1;
		cin >> n >> m >> k;
		cin >> y >> x >> d;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= k; i++){
			if(d == 0){
				if(x+1 <= m && y <= n && a[y][x+1] == '.'){
					x++;
					vis[y][x] = 1;
					if(!vis[y][x+1]) ans++;
			}
				else d = (d+1)%4;
			}
			else if(d == 1){
				if(x <= m && y+1 <= n && a[y+1][x] == '.'){
					y++;
					vis[y][x] = 1;
					if(!vis[y+1][x]) ans++;
				}
				else d = (d+1)%4;
			}
			else if(d == 2){
				if(x-1 <= m && y <= n && x-1 >= 1 && y >= 1 && a[y][x-1] == '.'){
					x--;
					vis[y][x] = 1;
					if(!vis[y][x-1]) ans++;
				}
				else d = (d+1)%4;
			}
			else if(d == 3){
				if(x <= m && y-1 <= n && x >= 1 && y-1 >= 1 && a[y-1][x] == '.'){
					y--;
					vis[y][x] = 1;
					if(!vis[y-1][x]) ans++;
				}
				else d = (d+1)%4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
