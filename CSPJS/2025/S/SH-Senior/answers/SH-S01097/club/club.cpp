#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, k, x, y, z, a[100005], b[100005], p[100005], d[100005], cnt[5], ans;
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x >> y >> z;
			if (x >= y && x >= z) a[i] = x, b[i] = max(y, z), cnt[p[i] = 1]++;
			else if (y >= x && y >= z) a[i] = y, b[i] = max(x, z), cnt[p[i] = 2]++;
			else a[i] = z, b[i] = max(x, y), cnt[p[i] = 3]++;
			ans += a[i];
		}
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2)
		{cout << ans << endl; continue;}
		for (int i = 1; i <= 3; i++) if (cnt[i] > n / 2) k = i;
		m = 0;
		for (int i = 1; i <= n; i++) if (p[i] == k) d[++m] = a[i] - b[i];
		sort(d + 1, d + m + 1);
		for (int i = 1; i <= m - n / 2; i++) ans -= d[i];
		cout << ans << endl;
	}
	return 0;
}
