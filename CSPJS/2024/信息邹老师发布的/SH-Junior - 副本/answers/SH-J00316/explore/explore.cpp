#include<bits/stdc++.h>
using namespace std;
int t, x, y, d, n, m, k, mp[1005][1005], vis[1005][1005], ans;
char c;
int wx[4] = {0, 1, 0 , -1};
int wy[4] = {1, 0, -1 , 0};
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> t;
	for(int q = 1; q <= t; q++)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				vis[i][j] = 0;
				cin >> c;
				if(c == 'x')
				{
					mp[i][j] = 0;
				}
				else
				{
					mp[i][j] = 1;
				}
			}
		}
		ans = 1;
		vis[x][y] = 1;
		for(int i = 1; i <= k; i++)
		{
			int xx, yy;
			xx = x + wx[d];
			yy = y + wy[d];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] == 1)
			{
				if(vis[xx][yy] == 0)
				{
					ans ++;
				}
				x = xx;
				y = yy;
				vis[xx][yy] = 1;
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
