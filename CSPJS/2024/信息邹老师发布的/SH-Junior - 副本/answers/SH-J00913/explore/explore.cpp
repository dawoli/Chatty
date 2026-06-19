#include <bits/stdc++.h>
using namespace std;

char mp[1005][1005];
bool vis[1005][1005];
int T, n, m, k, nx, ny, nd, ans;
int mx[] = {0, 1, 0, -1};
int my[] = {1, 0, -1, 0};

void solve()
{
	cin >> n >> m >> k;// 长、宽、步数 
	cin >> nx >> ny >> nd;// 初始的坐标 & 方向 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];// 输入地图 
	vis[nx][ny] = true;// 标记起点为到过 
	while (k--)// k 次操作 
	{
		int new_x = nx + mx[nd], new_y = ny + my[nd];// 下一次要站的位置 
		if (new_x < 1 || new_x > n || new_y < 1 || new_y > m)	nd = (nd + 1) % 4;
		// 越界了，要换方向 
		else if (mp[new_x][new_y] == 'x')	nd = (nd + 1) % 4;
		// 不能走，也要换方向 
		else	nx = new_x, ny = new_y, vis[nx][ny] = true;
		// 否则可以走，标记为来过 
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += vis[i][j];
	// 到过就 +1 
	cout << ans << endl;//输 出 
	ans = 0;
	memset(vis, false, sizeof vis);
	// 多测要清空 
}

int main()
{
	freopen ("explore.in", "r", stdin);
	freopen ("explore.out", "w", stdout);
	cin >> T;
	while (T--)	solve();// T 组样例 
	return 0;
}

// 1. 09:07 可以过所有样例 
// 2. 10:14 完成简单注释标记 
