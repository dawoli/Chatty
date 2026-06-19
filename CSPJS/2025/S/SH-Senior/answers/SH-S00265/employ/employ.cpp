#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, c[505], f[300005][20], ans;
string s;
const ll mod = 998244353;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	s = '*' + s;
	for (ll i = 1; i <= n; i++) cin >> c[i];
	f[0][0] = 1;
	for (ll i = 1; i < (1 << n); i++)
	{
		ll tmp = i, cnt = 0;
		while (tmp)
		{
			cnt += (tmp & 1);
			tmp >>= 1;
		}
		for (ll k = 1; k <= n; k++)
		{
			if ((i & (1 << (k - 1))) == 0) continue;
			for (ll j = 0; j < cnt; j++)
			{
				if (cnt - j - 1 >= c[k] || s[cnt] == '0')
				{
					(f[i][j] += f[i - (1 << (k - 1))][j]) %= mod;
				}
				else
				{
					(f[i][j + 1] += f[i - (1 << (k - 1))][j]) %= mod;
				}
			}
		}
		//cout << i << "\n";
		//for (ll j = 0; j <= cnt; j++) cout << f[i][j] << " ";
		//cout << "\n";
	}
	for (ll i = m; i <= n; i++) (ans += f[(1 << n) - 1][i]) %= mod;
	cout << ans;
}
