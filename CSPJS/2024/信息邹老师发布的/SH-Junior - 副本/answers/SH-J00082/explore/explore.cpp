#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, k, x, y, d, cnt = 0;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char c[N][N];
bool v[N][N];
void dfs(int x, int y, int d, int p)
{
	if (v[x][y] == false) cnt++;
	v[x][y] = true;
	if (p > k) return ;
	int nx = x + dx[d], ny = y + dy[d];
	if (nx < 1 || nx > n || ny < 1 || ny > m)
	{
		d = (d + 1) % 4;
		dfs(x, y, d, p + 1);
		return ;
	}
	if (c[nx][ny] == 'x')
	{
		d = (d + 1) % 4;
		dfs(x, y, d, p + 1);
		return ;
	}
	dfs(nx, ny, d, p + 1);
}
void solve()
{
	cnt = 0;
	memset(c, 0, sizeof(c)); 
	memset(v, false, sizeof(v));
	scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
		}
	}
	dfs(x, y, d, 1);
	printf("%d\n", cnt);
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
