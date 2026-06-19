#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5009;
const int V = 10001;
int n,a[N],f[2][N<<1],ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= V; ++j) f[i & 1][j] = 0;
		for (int j = 0; j <= V; ++j) (f[i & 1][min(V, j + a[i])] += f[(i & 1) ^ 1][j]) %= mod;
		for (int j = 2 * a[i] + 1; j <= V; ++j) (ans += f[i & 1][j]) %= mod;
		for (int j = 0; j <= V; ++j) (f[i & 1][j] += f[(i & 1) ^ 1][j]) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}