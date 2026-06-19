#include <iostream>
#include <cstdio>
using namespace std;
int n, m, k, u[1000005], v[1000005], w[1000005], c[15], a[15][10005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << ans;
	return 0;
}
