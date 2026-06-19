#include<bits/stdc++.h>
using namespace std;
long long T, n, m, k, x, y, d, ans;
int walkx[4] = {0, 1, 0, -1}, walky[4] = {1, 0, -1, 0};
int mp[1005][1005], vis[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		memset(mp, 0, sizeof mp);
		memset(vis, 0, sizeof vis);
		ans = 1;
		cin >> n >> m >> k >> x >> y >> d;
		vis[x][y] = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				char a;
				cin >> a;
				if(a != '.')
				{
					mp[i][j] = -1;
					vis[i][j] = -1;
				}
			}
		}
		for(int i = 1; i <= k; i++)
		{
			int nx = x + walkx[d];
			int ny = y + walky[d];
			if(nx > 0 && nx <= n && ny > 0 && ny <= m && vis[nx][ny] != -1)
			{
				if(vis[nx][ny] == 0)
				{
					vis[nx][ny] = 1;
					ans++;
				}
				x = nx;
				y = ny;
			}
			else
			{
				d = (d + 1) % 4; 
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
