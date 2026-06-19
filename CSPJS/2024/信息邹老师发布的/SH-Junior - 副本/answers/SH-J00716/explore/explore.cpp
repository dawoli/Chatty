#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,d,x,y,ans;
bool vis[1005][1005];
bool grid[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		for(int i = 0; i < 1005; i++){
			for(int j = 0; j < 1005;j++){
				vis[i][j] = false;
			} 
		}
		
		
		cin >> n >> m >>k >>x >> y >>d;
		for(int i = 0; i < 1005; i++){
			grid[i][0] = true;
			grid[0][i] = true;
			grid[n+1][i] = true;
			grid[i][m+1]=true;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char c;
				cin >>c;
				if(c == 'x'){
					grid[i][j] = true;
				}
				else grid[i][j] = false;
 			}
		}
		vis[x][y] = true;
		for(int i = 0; i < k; i++){
			if(!grid[x+dx[d]][y+dy[d]]){
				x += dx[d];
				y += dy[d]; 
				vis[x][y] = true;
			}
			else{
				d ++;
				d %= 4;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(vis[i][j]){
					ans++;
				}
			}
		} 
		cout << ans << '\n';
	} 
	return 0;
}
