#include <bits/stdc++.h>
using namespace std;
const int N = 1000000005;
int a[10015][10015], b[15][10015], n, w[15], ans = N;
int vis[10015];
int p[10015];
void dfs(){
	int cnt = 1, minn = N, sum = 0, next, pre;
	p[0] = 1;
	vis[1] = 1;
	while(cnt < n){
		minn = N;
		for(int i = 0;i < cnt;i++){
			for(int j = 1;j <= n;j++){
				if(!vis[j] && j != p[i]){
					if(a[p[i]][j] <= minn){
						next = j;
						pre = p[i];
						minn = a[pre][next];
					}
				}
			}
		}
		sum += a[pre][next];
		p[cnt++] = next;
		vis[next] = 1;
	}
	cout << sum;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int m, k, x, y, z;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			a[i][j] = N;
		}
	}
	for(int i = 0;i < m;i++){
		cin >> x >> y >> z;
		a[x][y] = z;
		a[y][x] = z;
	}
	for(int i = 1;i <= k;i++){
		cin >> w[i];
		for(int j = 1;j <= n;j++){
			cin >> x;
			b[i][j] = x + w[i];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int t = 1;t <= k;t++){
				a[i][j] = min(a[i][j], b[t][i] + b[t][j] - w[i]);
			}
		}
	}
	dfs();
	return 0;
}
