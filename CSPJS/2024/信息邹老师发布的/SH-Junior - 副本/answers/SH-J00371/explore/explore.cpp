#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MXN = 1e3 + 5;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char c[MXN][MXN];
bool vis[MXN][MXN];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		memset(vis,0,sizeof(vis));
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				cin >> c[i][j];
			}
		}
		int ans = 1;
		vis[x][y] = true;
//		cout << "(" << x << "," << y << ")" << endl;
		for (int i = 1;i <= k;i++)
		{
			int nx = x + dx[d],ny = y + dy[d];
			if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == 'x')
			{
				d = (d + 1) % 4;
				continue;
			}
			x = nx,y = ny;
//			cout << "(" << x << "," << y << ")" << endl;
			if (!vis[x][y])
			{
				ans++;
				vis[x][y] = true;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
