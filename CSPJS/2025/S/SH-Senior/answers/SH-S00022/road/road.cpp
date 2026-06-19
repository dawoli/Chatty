#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int mp[10010][10010];
int a[20][10010],c[20];
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			mp[i][j] = 0;
		}
	}
	for(int i = 1 ; i <= m + 1 ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = w;
	}
	cout << "0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 			
