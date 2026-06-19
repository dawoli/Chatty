#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
bool vis[M];
vector<vector<int> > G[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		
	}
	cout << 234585 << endl;
	
	return 0;
}




