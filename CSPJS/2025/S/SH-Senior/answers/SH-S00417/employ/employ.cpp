#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int MOD = 998244353;
int n, m, c[N], sum[N], ans;
bool a[N], vis[N];
void dfs(int x, int cnt)
{
	if (x == n + 1)
	{
		if (cnt <= n - m)
			ans++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		vis[i] = 1;
		if (a[x] == 0)
			dfs(x + 1, cnt + 1);
		else if (cnt >= c[i])
			dfs(x + 1, cnt + 1);
		else
			dfs(x + 1, cnt);
		vis[i] = 0;
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1, 0);
	cout << ans % MOD;
}
// 30
