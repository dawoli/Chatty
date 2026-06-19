#include<bits/stdc++.h>
using namespace std;
long long t, ans;
long long n, m, k;
long long x, y, d;
string a[1005];
bool vis[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		ans = 1;
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
			}
		}
		vis[x][y] = 1;
		while(k != 0)
		{
			k--;
			if(d == 0)
			{
				if(a[x][y + 1] == '.' && x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m)
				{
					y++;
					if(vis[x][y] == 0)
					{
						ans++;
						vis[x][y] = 1;
					}
				}
				else{
					d = (d + 1) % 4;
				}
			}
			else if(d == 1)
			{
				if(a[x + 1][y] == '.' && x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m)
				{
					x++;
					if(vis[x][y] == 0)
					{
						ans++;
						vis[x][y] = 1;
					}
				}
				else{
					d = (d + 1) % 4;
				}
			}
			else if(d == 2)
			{
				if(a[x][y - 1] == '.' && x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m)
				{
					y--;
					if(vis[x][y] == 0)
					{
						ans++;
						vis[x][y] = 1;
					}
				}
				else{
					d = (d + 1) % 4;
				}
			}
			else if(d == 3)
			{
				if(a[x - 1][y] == '.' && x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m)
				{
					x--;
					if(vis[x][y] == 0)
					{
						ans++;
						vis[x][y] = 1;
					}
				}
				else{
					d = (d + 1) % 4;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
