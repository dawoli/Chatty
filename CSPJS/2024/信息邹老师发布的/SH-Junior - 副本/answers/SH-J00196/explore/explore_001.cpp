#include <bits/stdc++.h>
using namespace std;

void testIO()
{
	int n;
	cin >> n;
	cout << n << endl;
}

const int N = 1000 + 5;
int T;
int n, m, k;
int x, y, d;
int cnt;
char a[N][N];
bool vis[N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	// testIO();
	cin >> T;
	while (T--)
	{
		memset(vis, 0, sizeof vis);
		cnt = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
		}
		vis[x][y] = 1;
		cnt++;
		for (int i = 1; i <= k; ++i)
		{
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x')
			{
				d = (d + 1) % 4;
			}
			else
			{
				if (!vis[nx][ny])
				{
					cnt++;
				}
				vis[nx][ny] = 1;
				x = nx, y = ny;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}