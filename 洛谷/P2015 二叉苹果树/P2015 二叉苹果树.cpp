// Problem URL: https://www.luogu.com.cn/problem/P2015
// Finish Time: 2026/7/9 14:42:30 AC
// Finish Time: 2026/7/9 14:37:28 WA 54pts
// Start Time: 2026/7/9 14:19:19

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 102;
struct Node
{
	int u, v;
} son[MAXN][2];
int n, q, dp[MAXN][MAXN], siz[MAXN];

void get_max(int &x, int y) // x = max(x, y)
{
	if (y > x)
		x = y;
}

void dfs(int u)
{
	const int &x = son[u][0].u, &y = son[u][1].u;
	if (!x && !y)
		return;
	dfs(x);
	dfs(y);
	siz[u] = siz[x] + siz[y] + 2;

	for (int i = -1; i <= siz[x]; i++)
		for (int j = -1; j <= siz[y]; j++)
		{
			int lv = i == -1 ? 0 : dp[x][i] + son[u][0].v;
			int rv = j == -1 ? 0 : dp[y][j] + son[u][1].v;
			get_max(dp[u][i + j + 2], lv + rv);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int side = son[x][0].u > 0;
		cin >> son[x][side].u >> son[x][side].v;
	}
	dfs(1);
	cout << dp[1][q];
	return 0;
}
