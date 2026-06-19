#include <bits/stdc++.h>
using namespace std;

int n, ans, a[100005], b[100005];

void dfs(int x)
{
	if (x > n)
	{
		int c = 0, d = 0;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (b[i] == 1) sum += (a[c] == a[i]) * a[i], c = i;
			else sum += (a[d] == a[i]) * a[i], d = i;
		}
		ans = max(ans, sum);
		return ;
	}
	b[x] = 1;
	dfs(x + 1);
	b[x] = 2;
	dfs(x + 1);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ans = 0;
		dfs(1);
		cout << ans << "\n";
	}
	return 0;
}
