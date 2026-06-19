#include <bits/stdc++.h>
using namespace std;

int n, m, k, x0, y0, d0, a[1008][1008], ans, vis[1008][1008];

void dfs(int x, int y, int d, int k)
{
	if(k == 0)
		return;

	int nx = x, ny = y;
	if(d == 0)
		ny = y + 1;
	if(d == 1)
		nx = x + 1;
	if(d == 2)
		ny = y - 1;
	if(d == 3)
		nx = x - 1;
		
	if(a[nx][ny] == 0)
	{
		if(vis[nx][ny] == 0)
			ans++;
		vis[nx][ny] = 1;
		dfs(nx, ny, d, k - 1);
	}
	else
	{
		int nd = (d + 1) % 4;
		dfs(x, y, nd, k - 1);
	}
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		ans = 1;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		memset(a, -1, sizeof(a));
		memset(vis, 0, sizeof(vis));
		vis[x0][y0] = 1;
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m ;j++)
			{
				char c;
				cin >> c;
				a[i][j] = (c == 'x') ? 1 : 0;
			}
		
		dfs(x0, y0, d0, k);
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
