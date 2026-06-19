#include<bits/stdc++.h>
using namespace std;

int t;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vis[1010][1010];
string graph[1010];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		x--;
		y--;
		for(int i = 0;i<n;i++){
			cin >> graph[i];
		}
		memset(vis, 0, sizeof(vis));
		
		int ans = 0;
		while(k--){
			
			int nx, ny;
			
			nx = x+dx[d];
			ny = y+dy[d];
			if(!vis[x][y]){
				ans++;
				//cout << x << " " << y << endl;
				vis[x][y] = 1;
			}
			if(nx<0||ny<0||nx>=n||ny>=m||graph[nx][ny] == 'x'){
				
				d = (d+1)%4;
				continue;
			}
			x = nx;
			y = ny;
			if(!vis[x][y]){
				ans++;
				//cout << x << " " << y << endl;
				vis[x][y] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


