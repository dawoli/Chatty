#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int x, y, d, ans, nx, ny;
bool vis[1005][1005];
char g[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for(int u = 1; u <= t; u++)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		ans = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> g[i][j];
		vis[x][y] = true;
		ans++;
		for(int i = 1; i <= k; i++)
		{
			nx = x + dx[d];
			ny = y + dy[d];
			if(nx && nx <= n && ny && ny <= m && g[nx][ny] == '.')
				x = nx, y = ny;
			else
				d++, d %= 4;
			if(!vis[x][y])
				ans++;
			vis[x][y] = true;
		}
		cout << ans << endl;
	}
	return 0;
}

