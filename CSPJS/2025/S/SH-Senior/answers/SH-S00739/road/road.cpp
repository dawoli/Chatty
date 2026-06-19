#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n,m,k,u,v,w,build[12][N],c[12];
long long edge[N][N];
int vis[N][N];
long long ans;
int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		edge[u][v] = edge[v][u] = w;
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
			cin >> build[i][j];	
	}	
	d[i] = d[i-1]
}
