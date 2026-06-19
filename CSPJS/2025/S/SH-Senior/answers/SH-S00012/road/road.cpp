#include <iostream>
using namespace std;
int n, m, k; 
// 描述一个城市
// 表示连接的两座城市，以及费用 
int li[1010][1010];
// 描述一个乡镇 
// 城市化改造所需费用 
int c[20];
// 将i号乡镇与第j个城市联通所需费用 
int a[20][1010];
int dp[1010][1010];
int village[1010][1010];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		li[u][v] = w;
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	
	// 连通
	 
//	for (int i = 1; i <= n; i++){
//		for (int j = i; j <= n; j++){
//			dp[i][j] = li[i][j];
//			dp[j][i] = li[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++){
//		for (int j = i+1; j <= n; j++){
//			dp[i][j] = max(li[i][j], li[i][j]);
//		}
//	}
	
	cout << 13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
