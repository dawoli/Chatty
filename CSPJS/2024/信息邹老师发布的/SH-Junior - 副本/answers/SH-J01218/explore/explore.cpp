#include <iostream>
#include<cstring>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int tt;
	cin >> tt;
	while(tt-->0)
	{
		memset(vis, 0, sizeof(vis));
		int n,m,kk;
		cin>>n>>m>>kk;
		int x,y,d;
		cin>>x>>y>>d;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", mp[i]+1);
		}
		vis[x][y]=true;
		for (int i = 1; i <= kk; i++)
		{
			int nxtx = x+dx[d];
			int nxty = y+dy[d];
			if (nxtx >= 1 && nxtx<=n&&nxty>=1&&nxty<=m&&mp[nxtx][nxty]=='.')
			{
				vis[nxtx][nxty] = true;
				x = nxtx;
				y = nxty;
			}
			else
			{
				d = (d + 1) % 4;
			}
		}
		int result = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (vis[i][j])
				{
					result++;
				}
			}
		}
		cout << result << endl;
	}
}
