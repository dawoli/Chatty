#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 109;
ll t, a[2 * N][3], f[2 * N][N][N][3];
		
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	for (ll _ = 1;_ <= t;_++)
	{
		ll n;
		scanf("%lld", &n);
		for (ll i = 1;i <= n;i++) scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
		for (ll i = 1;i <= n;i++) for (ll j = 0;j <= n / 2;j++) for (ll k = 0;k <= n / 2;k++)
		{
			if (j > 0) f[i][j][k][0] = max(max(f[i - 1][j - 1][k][0] + a[i][0], f[i - 1][j - 1][k][1] + a[i][0]), f[i - 1][j - 1][k][2] + a[i][0]);
			if (k > 0) f[i][j][k][1] = max(max(f[i - 1][j][k - 1][0] + a[i][1], f[i - 1][j][k - 1][1] + a[i][1]), f[i - 1][j][k - 1][2] + a[i][1]);
			if (j + k < n) f[i][j][k][2] = max(max(f[i - 1][j][k][0] + a[i][2], f[i - 1][j][k][1] + a[i][2]), f[i - 1][j][k][2] + a[i][2]);
		}
		ll ans = 0;
		for (ll j = 1;j <= n / 2;j++) for (ll k = 1;k <= n / 2;k++)
		{
			if (j + k < n / 2) continue;
			ans = max(max(ans, f[n][j][k][0]), max(f[n][j][k][1], f[n][j][k][2]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

