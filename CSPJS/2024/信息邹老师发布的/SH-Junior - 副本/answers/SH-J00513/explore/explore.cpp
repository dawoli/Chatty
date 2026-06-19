#include <bits/stdc++.h>
using namespace std;

int t;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int a[1005][1005]; // a[i][j]是0代表空地，1代表障碍。 
int visited[1005][1005]; // 表示是否经过，便于统计答案 

int main(){
	// 输入输出流重定向 
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	// 输入数据次数 
	cin >> t;
	while(t--){
		// 格式化 
		memset(visited, false, sizeof(visited));
		// 输入 
		int ans = 0;
		int n, m, k;
		cin >> n >> m >> k;
		int nx, ny, nd;
		cin >> nx >> ny >> nd;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char ch;
				cin >> ch;
				if(ch == 'x') a[i][j] = 1;
				if(ch == '.') a[i][j] = 0;
			}
		}
		
		// 模拟 
		for(int i = 0; i < k; i++){
			// 统计未走过的格子数量 
			if(visited[nx][ny] == false) ans++;
			visited[nx][ny] = true;
			// 计算下一个格子 
			int nxt_x = nx + dx[nd];
			int nxt_y = ny + dy[nd];
			// 判断是否能前进 
			if(nxt_x >= 1 && nxt_x <= n && nxt_y >= 1 && nxt_y <= m && a[nxt_x][nxt_y] == 0){
				nx = nxt_x;
				ny = nxt_y;
			}
			// 否则向右转 
			else{
				nd = (nd + 1) % 4; 
			}
		}
		// 最后判断一次，防止漏掉 
		if(visited[nx][ny] == false) ans++;
		cout << ans << endl;
	}
	// 关闭重定向 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
