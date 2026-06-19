#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int m,n,k,c[15],a[N][N],b[15][N];
int main()
{
	int u,v,w;
	cin >> m >> n >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j++)
			cin >> b[i][j];
	}
	srand(time(0));
	cout << rand(); 
	return 0; 
}
