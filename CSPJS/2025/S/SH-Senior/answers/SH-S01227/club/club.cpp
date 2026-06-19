#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 8;
const int pMAXN = 205;
int n;
int a[MAXN][4];
int dp[pMAXN][pMAXN][pMAXN];//dp[a][b][c]:当前a个人，1部门b个人，2部门c个人 
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		n = 0;
		scanf("%d", &n);
		if (n <= 200)
		{
			for (int i = 0; i < 201; i++) a[i][0] = a[i][1] = a[i][2] = a[i][3] = 0;
			for (int i = 0; i < 201; i++)
				for (int j = 0; j < 201; j++)
					for (int k = 0; k < 201; k++)
						dp[i][j][k] = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					scanf("%d", &a[i][j]);
				}
			}
			for (int i = 1; i <= n; i++)
			{
				int jf = min(n / 2, i - 1);
				for (int j = 0; j <= jf; j++)
				{
					int jk = min(n / 2, i - 1);
					for (int k = 0; k <= jk; k++)
					{
						if (j + k > i - 1) break;
						int tc = i - j - k - 1;
						if (tc <= n / 2 && j + 1 <= n / 2)
						{
							dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i - 1][j][k] + a[i][1]);
						}
						if (tc <= n / 2 && k + 1 <= n / 2)
						{
							dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i - 1][j][k] + a[i][2]);
						}
						if (tc + 1 <= n / 2)
						{
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
						}
					}
				}
			}
			int ans = 0;
			for (int i = 0; i <= n / 2; i++)
			{
				for (int j = 0; j <= n / 2; j++)
				{
					ans = max(ans, dp[n][i][j]);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
/**
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


**/
