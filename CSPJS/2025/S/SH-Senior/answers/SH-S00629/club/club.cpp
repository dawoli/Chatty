#include <bits/stdc++.h>
using namespace std;
int n, t;
struct node
{
	int a, b, c;
} a[100005];
int dfs200(int pos, int ca, int cb, int cc, int num)
{
	if (pos > n){
		if (ca > n / 2 || cb > n / 2 || cc > n / 2)
		{
			return 0;
		}
		return num;
	}
	int ans = 0;
	ans = max(ans, dfs200(pos + 1, ca + 1, cb, cc, num + a[pos].a));
	ans = max(ans, dfs200(pos + 1, ca, cb + 1, cc, num + a[pos].b));
	ans = max(ans, dfs200(pos + 1, ca, cb, cc + 1, num + a[pos].c));
	return ans;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		if (n == 2)
		{
			int ans = max(max(a[1].a + a[2].b, a[1].a + a[2].c), max(a[1].b + a[2].a, a[1].b + a[2].c));
			ans = max(ans, max(a[1].c + a[2].a, a[1].c + a[2].b));
			cout << ans <<"\n";
			continue;
		}
		if (n <= 10)
		{
			cout << dfs200(1, 0, 0, 0, 0) << "\n";
			continue;
		}
		cout << 0 <<"\n";
	}
	return 0;
}
