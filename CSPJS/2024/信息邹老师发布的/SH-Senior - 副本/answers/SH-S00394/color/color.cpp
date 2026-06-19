#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, a[N], ans;
void dfs(int x, int sum, int pre0, int pre1)
{
	if (x == n + 1)
	{
		ans = max(ans, sum);
		return;
	}
	dfs(x + 1, sum + a[pre1] * (a[x] == a[pre1]), pre0, x);
	dfs(x + 1, sum + a[pre0] * (a[x] == a[pre0]), x, pre1);
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		dfs(1, 0, 0, 0);
		cout << ans << "\n";
	}
}
