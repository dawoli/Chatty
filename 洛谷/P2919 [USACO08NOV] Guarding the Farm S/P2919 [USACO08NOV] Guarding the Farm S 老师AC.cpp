#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 7e2 + 2;

int	 n, m, h[MAXN][MAXN], ans = 0;
bool vis[MAXN][MAXN];
pii	 dir[8] = {{0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}};

void dfs(int x, int y)
{
	if (vis[x][y])
		return;
	vis[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;
		// 【修改1】增加边界判断
		if (nx < 1 || nx > n || ny < 1 || ny > m)
			continue;
		if (h[nx][ny] == h[x][y])
			dfs(nx, ny);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> h[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			bool flag = false;
			for (int k = 0; k < 8; k++)
			{
				int nx = i + dir[k].first;
				int ny = j + dir[k].second;
				// 【修改2】增加边界判断
				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (h[nx][ny] > h[i][j])
				{
					flag = true;
					break;
				}
			}
			if (flag)
				dfs(i, j);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j])
			{
				ans++;
				dfs(i, j);
			}
	cout << ans << endl;
	return 0;
}
/*
 * 经验总结：
 * - 这题本质是求等高连通块数，核心思路是从“局部峰值”出发做 DFS；如果不做边界判断，会访问到 h[0][*]、h[*][0]、h[n+1][*] 等非法下标。
 * - 容易错的地方：`dfs` 里直接访问 `h[x + dx][y + dy]`，没有先检查 `nx, ny` 是否在 1..n / 1..m 内；这是未定义行为，可能把不该连通的区域错误合并，导致答案偏大。
 * - 关键结论：`>` 判断和 `==` 判断都必须先判边界；越界访问不只是“读到 0”，而是 UB，结果经常随机变化。
 * - 复杂度：O(n * m * 8)，空间 O(n * m)。
 */
// 判断 nx, ny是否在 1 ~n, 1 ~m 范围内，这样就可以AC了 @Claude