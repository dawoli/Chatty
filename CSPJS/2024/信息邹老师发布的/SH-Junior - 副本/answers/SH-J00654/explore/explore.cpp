#include <bits/stdc++.h>
using namespace std;
const int NM = 1010;

int g[NM][NM];
bool vis[NM][NM];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		vis[x][y] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '.')	g[i][j] = 1;
			}
		while (k--)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (g[nx][ny] == 1)	x = nx, y = ny, vis[nx][ny] = 1;
			else	d = (d + 1) % 4;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (vis[i][j])
					ans++;
		cout << ans << endl;
	}
	return 0;
}
