#include <iostream>
#include <cstring>
using namespace std;

char mp[1005][1005];
bool flag[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, k;
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		memset(flag, false, sizeof(flag));
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		flag[x][y] = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mp[i][j];
		while (k--){
			int nx = x + dx[d], ny = y + dy[d];
			if (in(nx, ny) && mp[nx][ny] == '.'){
				x = nx;
				y = ny;
				flag[x][y] = true;
			} else {
				d = (d + 1) % 4;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (flag[i][j])
					ans++;
		cout << ans << endl;
	}
	return 0;
}
