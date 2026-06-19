#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long ans = 0;
const int MAXN = 10005;
int adj[MAXN][MAXN] = {};
int fix[MAXN][MAXN] = {};
bool flag = false;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u][v] = adj[v][u] = w;
		fix[u][v] = fix[v][u] = -1;
	}
	
	for (int i = 1; i * i <= n; i++)
	{
		for (int j = 1; j * j <= n; j++)
		{
			if (fix[i][j] == -1)
			{
				flag = true;
				ans += adj[i][j];
				fix[i][j] = fix[j][i] = 1;
				for (int x = 1; x * x <= n; x++)
				{
					for (int y = 1; y * y <= n; y++)
					{
						if (fix[x][y] == -1)
						{
							flag = false;
							break; 
						} 
					}
				}
				if (flag)
				{
					cout << ans;
					return 0;
				}
			}
			
		}
	}
	return 0;
}
