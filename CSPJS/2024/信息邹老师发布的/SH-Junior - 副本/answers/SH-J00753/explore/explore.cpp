#include <iostream>
#include <cstdio>
using namespace std;
int T,n,m,k,x_0,y_0,d_0,ans;
char g[1010][1010],vis[1010][1010];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while (T--)
	{
		ans = 1;
		cin >> n >> m >> k >> x_0 >> y_0 >> d_0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> g[i][j];
		int x = x_0, y = y_0,d = d_0;
		for (int i = 1; i <= k; i++)
		{
			x += dx[d],y += dy[d];
			if (x < 1 || x > n || y < 1 || y > m || g[x][y] == 'x')
			{
				x -= dx[d],y -= dy[d];
				d = (d+1) % 4;
			}
			else
			{
				if (!vis[x][y]) ans++;
				vis[x][y] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
