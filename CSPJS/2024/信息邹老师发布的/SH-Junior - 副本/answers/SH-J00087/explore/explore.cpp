#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T;
char c[1005][1005];
bool vis[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		memset(vis,0,sizeof vis);
		int n,m,k,x0,y0,d0,ans = 0;
		bool flag = 1;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		vis[x0][y0] = 1;
		ans = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> c[i][j];
			}
		}
		for(int i = 0;i <= m + 1;i++){
			c[0][i] = 'x';
			c[n + 1][i] = 'x';
		}
		for(int i = 0;i <= n + 1;i++){
			c[i][0] = 'x';
			c[i][m + 1] = 'x';
		}
		int step = 0;
		while(step <= k){
			while(c[x0 + dx[d0]][y0 + dy[d0]] == 'x'){
				d0 = (d0 + 1) % 4;
				step++;
			}
			if(step + 1 > k) break;
			if(!vis[x0 + dx[d0]][y0 + dy[d0]]) ans++; 
			step++;
			vis[x0 + dx[d0]][y0 + dy[d0]] = 1;
			x0 += dx[d0];
			y0 += dy[d0];
		}
		cout << ans << "\n";
	}
	return 0;
}
