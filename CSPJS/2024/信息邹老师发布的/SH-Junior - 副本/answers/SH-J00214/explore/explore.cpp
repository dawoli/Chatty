#include<bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
int x0, y0, d;

char mp[1005][1005];//地图 
int ans[1005][1005];//记录机器人走过的地方

int x[4] = {0, 1, 0, -1};//方向数组 
int y[4] = {1, 0, -1, 0};

bool check(int nx, int ny){
	if(1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] == '.') return 1;
	
	return 0;
}

void bfs(int xx, int yy, int k, int d){
	ans[xx][yy] = 1;
	
	if(k == 0) return;
	
	if(check(xx + x[d], yy + y[d])) bfs(xx + x[d], yy + y[d], k - 1, d);
	else bfs(xx, yy, k - 1, (d + 1) % 4);
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> T;
	
	while(T--){
		for(int i = 1;i <= 1000;i++){
			for(int j = 1;j <= 1000;j++){
				ans[i][j] = 0;
			}
		}
		
		cin >> n >> m >> k >> x0 >> y0 >> d;
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> mp[i][j];
			}
		}
		
		bfs(x0, y0, k, d);
		
		int cnt = 0;
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(ans[i][j] != 0) cnt++;
			}
		}
		
		cout << cnt << endl;
	}
	return 0;
}
