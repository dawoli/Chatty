#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1001;
const int mod = 4;
char map1[maxn][maxn];
int T, n, m, k, x_0, y_0, d_0;
bool vis[maxn][maxn];
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};
int main(){
	freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cin >> x_0 >> y_0 >> d_0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				cin >> map1[i][j];
		}
		vis[x_0][y_0] = true;
		int x = x_0, y = y_0;
		while(k--){
			int nxtx = x + dx[d_0];
			int nxty = y + dy[d_0];
			if(map1[nxtx][nxty] == '.' && nxtx >= 1 && nxtx <= n && nxty >= 1 && nxty <= m){
				vis[nxtx][nxty] = true;
				x = nxtx, y = nxty;
			}
			else
				d_0 = (d_0 + 1) % mod;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(vis[i][j])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
