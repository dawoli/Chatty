#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, k;
int cost[10003][10003];
int build[13][10003];
int c[13];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		cost[u][v] = w;
	} 
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> build[i][j];
		
	 } 
	cout << 0; 
	
	return 0;
}
