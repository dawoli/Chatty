#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
char mp[N][N];
bool vis[N][N];

void solve(){
	memset(vis, false, sizeof vis);
	int n, m, k;
	cin >> n >> m >> k;
	int x, y, d;
	cin >> x >> y >> d;
	vis[x][y] = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	int nx, ny, ans = 0;
	for (int i = 1; i <= k; i++){
		if (d == 0)
			nx = x, ny = y+1;
		else if (d == 1)
			nx = x+1, ny = y;
		else if (d == 2)
			nx = x, ny = y-1;
		else
			nx = x-1, ny = y;
		if (1<=nx && nx<=n && 1<=ny && ny<=m && mp[nx][ny] == '.'){
			x = nx, y = ny;
			vis[x][y] = true;
		} else{
			d = (d+1) % 4;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (vis[i][j]) ans++;
	cout << ans << endl;
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
