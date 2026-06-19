#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, u[N], v[N], w[N], c[15], a[15][10005];
long long ans, e[N][N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset(e, 0x3f, sizeof(e));
	for (int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]][v[i]] = e[v[i]][u[i]] = w[i];
		vis[i] = 1;
	}
	for (int j = 1; j <= k; j++){
		cin >> c[j];
		for (int i = 1; i <= n; i++){
			cin >> a[j][i];
		}
	}
	bool flag = 1;
	while (flag){
		flag = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int t = 1; t <= n; t++){
					if (t == i || t == j) continue;
					int cost = e[i][t] + e[t][j];
					if (e[i][j] > cost){
						e[i][j] = e[j][i] = cost;
						flag = 1;
					}
				} for (int t = 1; t <= k; t++){
					int cost = c[t] + a[t][i] + a[t][j];
					if (e[i][j] > cost){
						e[i][j] = e[j][i] = cost;
						flag = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++){
		ans = max(ans, e[i][j]);
	}
	cout << ans;
	return 0;
} 
