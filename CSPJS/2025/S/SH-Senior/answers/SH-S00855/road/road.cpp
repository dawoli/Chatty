#include <bits/stdc++.h>
using namespace std;
struct road
{
	int v, c;
};
int ans = 0;
int cv[19];
int cst[15][1009];
bool built[19];
vector <road> to[1009];
int n, m, k;
int main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		to[u].push_back({v, cost});
		to[v].push_back({u, cost});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> cv[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> cst[i][j];
		}
	}
	for (int u = 1; u <= n; u++)
	{
		for (int i = 0; i < to[u].size(); i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int costnew = cv[j] + cst[j][u] + cst[j][to[u][i].v];
				if (costnew < to[u][i].c)
				{
					to[u][i].c = costnew;
					built[j] = true;
				}
			}
		}
	}
	for (int u = 1; u <= n; u++)
	{
		for (int i = 0; i < to[u].size(); i++)
		{
			ans += to[u][i].c;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
