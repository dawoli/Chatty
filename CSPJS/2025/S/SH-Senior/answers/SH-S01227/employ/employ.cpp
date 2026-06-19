#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int n, m, ans;
char a[MAXN];
int c[MAXN], path[MAXN];
bool vis[MAXN];
void dfs (int root, int cur/** ÕÐÆ¸µ½µÄ **/)
{
	if (root > n)
	{
		if (cur >= m)
		{
			ans++;
		}
		return;
	}
	if (cur + (n - root + 1) < m) return; 
	if (cur >= m)
	{
		int res = 1;
		for (int i = 2; i <= n - root + 1; i++)
		{
			res *= i;
		}
		ans += res;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			path[root] = i;
			if (root - cur - 1 >= c[i] || a[root] == '0')
			{
				dfs(root + 1, cur);
			}
			else
			{
				dfs(root + 1, cur + 1);
			}
			path[root] = 0;
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	dfs (1, 0);
	cout << ans;
	return 0;
}

