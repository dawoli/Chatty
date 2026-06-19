#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500 + 5, mod = 998244353;

bool flag = true, vis[N];
int n, m, ans, s[N], c[N];

void dfs (int step, int chs)
{
	if (step > n)
	{
		if (chs >= m)	ans = (ans + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])	continue;
		vis[i] = true;
		if (step - 1 - chs >= c[i])	dfs (step + 1, chs);
		else	dfs (step + 1, chs + s[step]);
		vis[i] = false;
	}
}

signed main()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		s[i] = c - '0';
		if (s[i] != 1)	flag = false;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 18)	
	{
		dfs(1, 0);
		cout << ans;
	}
	else if (flag)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
			ans = ans * i % mod;
		cout << ans;
	}
	return 0;
}
