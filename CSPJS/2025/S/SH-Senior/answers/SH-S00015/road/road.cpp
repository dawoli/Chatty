#include<fstream>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using ll = long long;
const ll INF = 1e10;

int main()
{
	std::ifstream fin("road.in");
	std::ofstream fout("road.out");

	int n, m, k;
	fin >> n >> m >> k;

	std::vector<std::vector<std::pair<int, ll>>> g(n + k + 1);
	std::vector<int> upgrade(k + 1);

int abc = INF;
	for(int i = 1; i <= m; ++i)
	{
		int u, v, w;
		fin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= k; ++i)
	{
		ll ans = 0;
		fin >> ans;
		g[i].push_back({m + i, upgrade[i]});
		for(int v = 1; v <= n; ++v)
		{
			int w;
			fin >> w;
			ans += w;
		}
		abc = std::min (abc, ans);
	}
	fout << ans;
}
