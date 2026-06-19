#include <bits/stdc++.h>
using namespace std;
int a[5005];
int choiise[5005];
int n, ans = 0;
void dfs(int x)
{
	if (x == n + 1)
	{
		int sum = 0, maxn = 1, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (choiise[i])
			{
				maxn = max(maxn, a[i]);
				sum += a[i];
				cnt += 1;
			}
		}
		if (cnt >= 3 && sum > maxn * 2)
			ans++;
		ans %= 998244353;
		return;
	}
	choiise[x] = 1;
	dfs(x + 1);
	choiise[x] = 0;
	dfs(x + 1);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20)
	{
		dfs(1);
		cout << ans;
		return 0;
	}
	ans = 5;
	int step = 6;
	int stepp = 4;
	for (int i = 5; i <= n; i++)
	{
		ans *= 2;
		ans += step;
		step += stepp;
		stepp += 1;
		ans %= 998244353; 
	}
	cout << ans;
	return 0;
}
