#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int g[100005];
int g2[100005];
int dp[505][505][505];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int q = 0; q <= n; q++)
					dp[i][j][q] = 0;
			}
		}
		bool specialA = true;
		bool specialB = true; 
		if (n <= 200)
		{
			specialA = false; 
			specialB = false;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0)
				specialA = false;
			if (a[i][3] != 0)
				specialB = false;
		}
		if (specialA == true)
		{
			for (int i = 1; i <= n; i++)
				g[i] = a[i][1];
			sort(g + 1, g + n + 1);
			long long ans = 0;
			for (int i = n; i >= n / 2 + 1; i--)
				ans += g[i];
			cout << ans; 
			return 0;
		}
		if (specialB == true)
		{
			long long ans = 0;
			for (int i = 1; i <= n; i++)
			{
				g[i] = a[i][1];
				g2[i] = a[i][2];
			}
			for (int i = 1; i <= n; i++)
			{
				if (g[i] > g2[i])
				{
					ans += g2[i];
					g[i] -= g2[i];
					g2[i] = 0;
				}
				else
				{
					ans += g[i];
					g2[i] -= g[i];
					g[i] = 0;
				}
			}
			sort(g + 1, g + n + 1);
			sort(g2 + 1, g2 + n + 1);
			for (int i = n; i >= n / 2 + 1; i--)
				ans += g[i] + g2[i];
			cout << ans; 
			return 0;
		}
		dp[1][0][0] = a[1][1];
		dp[0][1][0] = a[1][2];
		dp[0][0][1] = a[1][3];
		int ans = 0;
		for (int sum = 1; sum <= n; sum++) // sum 表示 i + j + q 之和
		{
			// 拆分 sum
			for (int i = 0; i <= sum; i++)
			{
				int jq = sum - i; // j + q 之和
				for (int j = 0; j <= jq; j++) // j
				{
					int q = jq - j;
					if (i != 0 && i <= n / 2)
						dp[i][j][q] = max(dp[i - 1][j][q] + a[sum][1], dp[i][j][q]);
					if (j != 0 && j <= n / 2)
						dp[i][j][q] = max(dp[i][j - 1][q] + a[sum][2], dp[i][j][q]);
					if (q != 0 && q <= n / 2)
						dp[i][j][q] = max(dp[i][j][q - 1] + a[sum][3], dp[i][j][q]);
					if (sum == n)
						ans = max(ans, dp[i][j][q]); 
				} 
			} 
		}
		cout << ans << endl;
	}
	return 0;
} 
