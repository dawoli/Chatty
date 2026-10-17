// Problem URL: https://www.luogu.com.cn/problem/P1388 算式
// Finish Time: 2026/10/13 17:10:08 AC
// Start Time: 2026/10/13 16:32:47

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 15 + 2;

ll	ans = -1, f[MAXN][MAXN];
int n, k, s[MAXN], a[MAXN];

auto cal(ll x, ll y, ll t)
{
	return t == 1 ? x + y : x * y;
}

ll dp()
{
	for (int i = 1; i <= n; i++)
		f[i][i] = a[i];
	int j;
	for (int l = 1; l <= n; l++)
		for (int i = 1; i + l - 1 <= n; i++)
		{
			j = i + l - 1;
			for (int k = i; k < j; k++)
				f[i][j] = max(f[i][j], cal(f[i][k], f[k + 1][j], s[k]));
		}
	return f[1][n];
}

int dfs(int x, int t1, int t2)
{
	if (x == n)
	{
		memset(f, 0, sizeof(f));
		ans = max(ans, dp());
		return 0;
	}
	if (t1 < k)
	{
		s[x] = 2;
		dfs(x + 1, t1 + 1, t2);
	}
	if (t2 < n - k - 1)
	{
		s[x] = 1;
		dfs(x + 1, t1, t2 + 1);
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}