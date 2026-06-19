#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, p, a[105], x[105], y[105];
string s;
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	k = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++) if (a[i] == k) {p = i; break;}
	k = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % 2) for (int j = 1; j <= n; j++) x[++k] = i, y[k] = j;
		else for (int j = n; j >= 1; j--) x[++k] = i, y[k] = j;
	}
	cout << x[p] << " " << y[p];
	return 0;
}
