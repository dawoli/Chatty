#include <bits/stdc++.h>
using namespace std;

int a[5010], v[5010];
int n, ans = 0;
//230138

void dfs(int step, int maxn, int sum, int last)
{
	if (step == n)
	{
		if (sum > maxn * 2) ans++;
		return;
	}
	if (step >= 3)
	{
		if (sum > maxn * 2)
		{
			ans++;
			return;
		}
	}
	for (int i = last + 1; i <= n; i++)
	{
		if (v[i] == 0) sum += a[i];
		v[i] = 1;
		dfs(step + 1, max(maxn, a[i]), sum, i);
		sum -= a[i];
		v[i] = 0;
	}
	//cout << step << " " << maxn << " " << sum << " " << last << endl;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dfs(0, -1e8, 0, 0);
	cout << ans << endl;
	return 0;
}
