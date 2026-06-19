#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
int n;
int a[MAXN];
int p[MAXN];
int dfs(int cur, int lr, int lb, int cans)
{
	if (cur == n + 1)
	{
		return cans;
	}
	int ret = 0;
	if (a[cur] == lr)
	{
		ret = max(ret, dfs(cur + 1, a[cur], lb, cans + lr));
	}
	else
	{
		ret = max(ret, dfs(cur + 1, a[cur], lb, cans));
	}
	if (a[cur] == lb)
	{
		ret = max(ret, dfs(cur + 1, lr, a[cur], cans + lb));
	}
	else
	{
		ret = max(ret, dfs(cur + 1, lr, a[cur], cans));
	}
	return ret;
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int cur = 0;
			scanf("%d", &cur);
			a[i] = cur;
		}
		if (n <= 15)
		{
			cout << dfs(1, 0, 0, 0) << endl;
			continue;
		}
		else
		{
			ll ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (p[a[i]] != 0)
				{
					ans += a[i];
				 } 
				 p[a[i]]++;
			}
			cout << ans << endl;
		} 
	}
 	return 0;
}
