#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> mp;
int a[15][10005]; 

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	for(int i = 1; i <= n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = 1;
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
