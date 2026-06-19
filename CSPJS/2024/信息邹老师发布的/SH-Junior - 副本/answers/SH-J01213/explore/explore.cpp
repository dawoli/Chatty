#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, d;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char a[1005][1005];
bool vis[1005][1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof vis);
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		vis[x][y] = 1;
		for (int i = 1; i <= k; i++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.') x = nx, y = ny, vis[nx][ny] = 1;
			else d = (d + 1) % 4;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (vis[i][j]) ans++;
		cout << ans << endl;
	}
	return 0;
} 
