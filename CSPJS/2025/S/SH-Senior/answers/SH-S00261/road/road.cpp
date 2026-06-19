#include <bits/stdc++.h>
using namespace std;

int n, m, k, u, v, w, c, a, ans = 0;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		ans += w;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n + 1; j++) cin >> a; 
	}
	cout << ans << endl;
	return 0;
}
