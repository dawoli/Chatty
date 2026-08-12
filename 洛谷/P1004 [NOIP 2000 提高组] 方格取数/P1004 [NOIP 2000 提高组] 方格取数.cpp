// Problem URL: https://www.luogu.com.cn/problem/P1004
// Finish Time: 2026/8/4 15:23:35 AC
// Start Time: 2026/8/4 14:59:30

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int	  MAXN = 10;

int n, v[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
int c[4][4] = {
	{-1, 0, -1, 0},
	{0, -1, 0, -1},
	{-1, 0, 0, -1},
	{0, -1, -1, 0}};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int x, y;
	while (cin >> x >> y >> v[x][y])
		if (x == 0 && y == 0)
			break;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				for (int l = 1; l <= n; l++)
					for (int m = 0; m < 4; m++)
					{
						if (dp[i][j][k][l] < dp[i + c[m][0]][j + c[m][1]][k + c[m][2]][l + c[m][3]] + v[i][j] + v[k][l] - (i == k && j == l ? v[i][j] : 0))
						{
							dp[i][j][k][l] = dp[i + c[m][0]][j + c[m][1]][k + c[m][2]][l + c[m][3]] + v[i][j] + v[k][l] - (i == k && j == l ? v[i][j] : 0);
						}
					}
	cout << dp[n][n][n][n];
	return 0;
}