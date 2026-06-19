#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int t, n, m, k, x0, y0, d0;
char mp[N][N];
bool vis[N][N];
void dfs(int x, int y, int d, int cnt)
{
	vis[x][y] = 1;
	if (cnt == k)
		return;
	int nx = x + dx[d], ny = y + dy[d];
	if (nx < 1 || nx > n|| ny < 1 || ny > m || mp[nx][ny] == 'x')
		dfs(x, y, (d + 1) % 4, cnt + 1);
	else
		dfs(nx, ny, d, cnt + 1);
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof vis);
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mp[i][j];
		dfs(x0, y0, d0, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				ans += vis[i][j];
		cout << ans << endl; 
	}
}
