#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std; 
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int t, n, m, d0, vis[1005][1005], sx, sy, k, kk, xx, yy, dd;
char mp[1005][1005];
void bfs()
{
	memset(vis, 0, sizeof vis);
	kk = 0;
	xx = sx, yy = sy, dd = d0;
	vis[xx][yy] = 1;
	while(true)
	{
		int nx = xx + dx[dd], ny = yy + dy[dd];
		while(nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x')
		{
			if(kk + 1 > k)break;
			dd = (dd + 1) % 4;
			kk++;
			nx = xx + dx[dd], ny = yy + dy[dd];
		}
		if(kk + 1 > k)break;
		kk++;
		if(!vis[nx][ny])vis[nx][ny]++;
		xx = nx, yy = ny;
	}
}
signed main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int cnt = 0;
		cin >> n >> m >> k;
		cin >> sx >> sy >> d0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> mp[i][j];
		bfs();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(vis[i][j])cnt++;
		cout << cnt << endl;
	}
}
