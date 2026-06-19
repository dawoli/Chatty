#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, a[100005][3], c[100005], f[205][105][105], ans;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ll tmp = 0;
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			tmp += a[i][1] + a[i][2];
		}
		if (tmp == 0)
		{
			for (ll i = 1; i <= n; i++) c[i] = a[i][0];
			sort(c + 1, c + n + 1);
			ans = 0;
			for (ll i = n; i > n / 2; i--) ans += c[i];
			cout << ans << "\n";
			continue;
		}
		memset(f, 0, sizeof(f));
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 0; j <= min(n / 2, i); j++)
			{
				for (ll k = 0; k <= min(n / 2, i) && k + j <= i; k++)
				{
					ll lst = i - j - k;
					if (lst > n / 2) continue;
					if (j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][0]);
					if (k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][1]);
					if (lst) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][2]);
				}
			}
		}
		ans = 0;
		for (ll i = 1; i <= n / 2; i++)
		{
			for (ll j = 1; j <= n / 2; j++)
			{
				ans = max(ans, f[n][i][j]);
			}
		}
		cout << ans << "\n";
	}
}
