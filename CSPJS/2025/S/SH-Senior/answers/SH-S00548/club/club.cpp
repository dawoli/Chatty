#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 205;

int t, n, ar[N][4], x[N], y[N], z[N], xa = 0, ya = 0, za = 0, f[2][M][M][M];
priority_queue<int> q;

void solve1()
{
	int cur = 0;
	for (int a = 0; a <= n; a ++ )
	{
		for (int b = 0; a + b <= n; b ++ )
		{
			for (int c = 0; c + a + b <= n; c ++ ) f[0][a][b][c] = f[1][a][b][c] = 0;
		}
	}
	for (int i = 1; i <= n; i ++ )
	{
		cur ^= 1;
		for (int a = 0; a <= i && a <= n / 2; a ++ )
		{
			for (int b = 0; a + b <= i && b <= n / 2; b ++ )
			{
				int c = i - a - b;
				if (c > n / 2) continue;
				if (a >= 1)
				{
					f[cur][a][b][c] = max(f[cur ^ 1][a - 1][b][c] + ar[i][1], f[cur][a][b][c]);
				}
				if (b >= 1)
				{
					f[cur][a][b][c] = max(f[cur ^ 1][a][b - 1][c] + ar[i][2], f[cur][a][b][c]);
				}
				if (c >= 1)
				{
					f[cur][a][b][c] = max(f[cur ^ 1][a][b][c - 1] + ar[i][3], f[cur][a][b][c]);
				}
			}
		}
	}
	int ans = 0;
	for (int a = 0; a <= n / 2; a ++ )
	{
		for (int b = 0; a + b <= n && b <= n / 2; b ++ )
		{
			int c = n - a - b;
			if (c > n / 2) continue;
			ans = max(ans, f[cur][a][b][c]);
		}
	}
	printf("%d\n", ans);
}

void solve2()
{
	while (!q.empty()) q.pop();
	int ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		ans += ar[i][1];
		q.push(ar[i][2] - ar[i][1]);
	}
	int cnt = n / 2;
	while (!q.empty() && cnt)
	{
		cnt -- ;
		ans += q.top();
		q.pop();
	}
	printf("%d\n", ans);
	
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t -- )
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= 3; j ++ )
			{
				scanf("%d", &ar[i][j]);
			}
		}
		if (n <= 200)
		{
			solve1();
		}
		else
		{
			solve2();
		}
	}
	
	return 0;
}
