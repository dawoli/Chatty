#include <iostream>

using namespace std;

int T;
int n, m, k;
int x, y, d;
char a[1010][1010];

int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};


int main(){
	
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> T;
	while(T--){
	    bool vis[1010][1010] = {0};
	    int ans = 1;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		vis[x][y] = 1; 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		
		for(int i = 1; i <= k; i++){
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == 'x') d = (d+1) % 4;
			else{
				x = nx;
				y = ny;
				if(vis[x][y] == 0){
					ans++;
					vis[x][y] = 1;
				}
			}
		}
		cout << ans << endl;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
