#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,m,k;
int g[N][N],c[N][13];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int a,b,v;
	for(int i = 1; i <= n; i ++){
		cin >> a >> b >> v;
		g[a][b] = v;
		g[b][a] = v;
	}
	for(int i = 1; i <= k; i ++)
		for(int j = 1; j <= k; j ++)
			cin >> c[i][j];
	return 0;
} 
