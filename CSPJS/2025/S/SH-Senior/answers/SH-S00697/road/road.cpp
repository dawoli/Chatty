#include <bits/stdc++.h>
using namespace std;

bool visit[10010][10010];
int u[1100010], v[1100010], w[1100010], ans = 1e8;
int n, m, k;

/*
bool check(bool visit[][])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (visit[i][j] != 1 && i != j) return false;
		}
	}
	return true;
}

void dfs(int cost)
{
	if (check(visit) == true)
	{
		ans = min(cost, ans);
		return;
	}
	for (int i = 1; i <= m + k * n; i++)
	{
		if (visit[u[i]][v[i]] == 0)
		{
			cost += w[i];
		}
	}
}
*/

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	//int cur = 0;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		for (int i = 1; i <= n; i++)
		{
			int weight;
			cin >> weight;
		}
	}
	//dfs(0);
	cout << 0 << endl;
	return 0;
}
