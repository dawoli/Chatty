#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans, p = 998244353;
const int N = 505;
int n, m, t, c[N];
bool s[N], b[N];
void dfs(int x, int d)
{
	cout << x << " " <<d << endl;
	if (x == n + 1)
	{
		cout << n - d<< " " << m << endl;
		if (n - d >= m)
		{
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!b[i])
		{
			t = (c[i] < d || !s[i]);
			d += t;
			b[i] = true;
			cout << i << endl;
			dfs(x + 1, d);
			b[i] = false;
			d -= t;
		}
	}
}
int main()
{
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		s[i] = getchar() - '0';
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1, 0);
	cout << ans;
}
