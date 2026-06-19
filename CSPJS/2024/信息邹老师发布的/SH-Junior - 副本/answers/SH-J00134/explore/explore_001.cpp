#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x0,y0,d0;
int dx[14] = {0,1,0,-1},dy[14] = {1,0,-1,0};
char g[1010][1010];
int main(){
	ifstream cin("explore.in");
	ofstream cout("explore.out");
	cin >> T;
	while(T --){
		int res = 0;
		memset(g,0,sizeof g);
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				cin >> g[i][j];
			}
		}
		g[x0][y0] = '#';
		res ++;
		while(k){
			x0 += dx[d0];
			y0 += dy[d0];
			if(x0 > n || x0 < 1 || y0 > m || y0 < 1 || g[x0][y0] == 'x'){
				x0 -= dx[d0];
				y0 -= dy[d0];
				d0 = (d0 + 1) % 4;
			}else{
				if(g[x0][y0] == '#'){
					k --;
					continue;
				}else{
					res ++;
					g[x0][y0] = '#';
				}
			}
			k --;
		}
		cout << res << endl;
	}
	return 0;
}
