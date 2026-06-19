#include<bits/stdc++.h>
using namespace std;

//GL@17SXYZ
//Y#C*GF@24

const int MAXN = 1005;
int map1[MAXN][MAXN];
int vis[MAXN][MAXN];
int x0, y0 ,d0, t, n, m, k = 0;

bool check(int x, int y){
	if(x > 0 && x <= n && y > 0 && y <= m && !map1[x][y]){
		return true;
	}return false;
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for(int ttt = 1; ttt <= t; ttt ++){
		memset(vis, 0, sizeof(vis));
		int ans = 1;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		for(int i = 1; i <= n; i++){
			string x;
			cin >> x;
			for(int j = 0; j <= m - 1; j ++){
				if(x[j] == '.') map1[i][j + 1] = 0;
				else map1[i][j + 1] = 1;
			}
		}
		vis[x0][y0] = 1;
		for(int i = 1; i <= k; i++){
			if(d0 == 0){
				if(check(x0, y0 + 1)){
					y0 ++;
					if(vis[x0][y0] == 0) ans ++;
					vis[x0][y0] = 1;
				}else{
					d0 = 1;
					continue;
				}
			}else if(d0 == 1){
				if(check(x0 + 1, y0)){
					x0 ++;
					if(vis[x0][y0] == 0) ans ++;
					vis[x0][y0] = 1;
				}else{
					d0 = 2;
					continue;
				}
			}else if(d0 == 2){
				if(check(x0, y0 - 1)){
					y0 --;
					if(vis[x0][y0] == 0) ans ++;
					vis[x0][y0] = 1;
				}else{
					d0 = 3;
					continue;
				}
			}else{
				if(check(x0 - 1, y0)){
					x0 --;
					if(vis[x0][y0] == 0) ans ++;
					vis[x0][y0] = 1;
				}else{
					d0 = 0;
					continue;
				}
			}
		}cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
