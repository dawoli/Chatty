#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[1000005], v[1000005], w[1000005];
int c[15], a[15][10005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool sp = 1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	int mn = 0x3f3f3f3f;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		int sum = c[i];
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			sum += a[i][j];
			if (a[i][j] != 0)
				sp = 0;
		}
		mn = min(mn, sum);
		if (c[i] != 0)
			sp = 0;
	}
	if (sp)
	{
		cout << 0;
		return 0;
	}
	cout << mn;
	return 0;
}
