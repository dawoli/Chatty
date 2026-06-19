#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], d[1050005], f[500005];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {cin >> a[i]; a[i] ^= a[i - 1];}
	memset(d, -1, sizeof d);
	d[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[a[i] ^ m] >= 0) f[i] = f[d[a[i] ^ m]] + 1;
		f[i] = max(f[i], f[i - 1]), d[a[i]] = i;
	}
	cout << f[n];
	return 0;
}
