#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,mod = 998244353;
int n,m,c[N],ans;
bool ls[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	bool x = 1;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		ls[i] = (c == '1');
		x |= ls[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) cin >> c[i],cnt += (c[i] != 0);
	sort(c + 1,c + n + 1);
	for (int s = 0; s < (1 << n); s++)
	{
		int cnt = 0,zz = s;
		while (zz) zz -= (zz & -zz),cnt++;
		if (cnt < m) continue;
		bool cc = 0;
		for (int i = 1; i <= n; i++)
			if ((s & (1 << i - 1)) && !ls[i])
			{
				cc = 1;
				break;
			}
		if (cc) continue;
		int num = 1,w = 0;
		for (int j = n; j >= 1; j--)
			if (s & (1 << j - 1))
			{
				int nn = j - cnt;
				int id = upper_bound(c + 1,c + n + 1,nn) - c;
				num = num * (n - id + 1 - w) % mod;
				w++; cnt--;
			}
		int aa = 0;
		for (int j = 1; j <= n; j++)
			if (!(s & (1 << j - 1)))
			{
				if (ls[j])
				{
					int id = upper_bound(c + 1,c + n + 1,aa) - c - 1;
					num = num * (id - aa) % mod;
				}
				aa++;
			}
		aa = 1;
		for (int j = 1; j <= n; j++)
			if (!(s & (1 << j - 1)))
			{
				if (!ls[j]) num = num * aa % mod,aa++;
			}
		ans += num; ans %= mod;
	}
	cout << ans;
	return 0;
}
