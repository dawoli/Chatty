// Problem URL: https://www.luogu.com.cn/problem/P2516
// Start Time: 2026/8/13 15:24:04

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 5e3 + 3;
const int		  MOD  = 1e8;

int	   n, m, f[2][MAXN], d[2][MAXN];
string a, b;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a;
	cin >> b;
	a.erase(--a.end());
	b.erase(--b.end());
	n = a.size();
	m = b.size();
	fill(d[0], d[0] + m + 1, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int x = i & 1, y = x ^ 1;
			f[x][j] = INT_MIN;
			if (f[y][j] > f[x][j])
			{
				f[x][j] = f[y][j];
				d[x][j] = d[y][j];
			}
			if (f[x][j - 1] > f[x][j])
			{
				f[x][j] = f[x][j - 1];
				d[x][j] = d[x][j - 1];
			}
			if (a[i - 1] == b[j - 1])
			{
				if (f[y][j - 1] + 1 > f[x][j])
				{
					f[x][j] = f[y][j - 1] + 1;
					d[x][j] = d[y][j - 1];
				}
			}
			if (a[i - 1] != b[j - 1] && d[x][j - 1] == d[y][j])
				d[x][j] = d[x][j - 1] + d[y][j] - d[y][j - 1];
			d[x][j] %= MOD;
		}
	cout << f[n & 1][m] << endl
		 << d[n & 1][m];
	return 0;
}