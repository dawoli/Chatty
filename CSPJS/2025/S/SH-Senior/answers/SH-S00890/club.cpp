#include<bits/stdc++.h>
# define int long long
# define rep(i, j, k) for (int i = j; i <= k; ++i)
# define N 100005
using namespace std;

int T, n, a[N][5], plc[N], cnt[5], maxx, num[N], now, ans;
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
	{
		memset(plc, 0, sizeof(plc)), memset(cnt, 0, sizeof(cnt)), memset(num, 0, sizeof(num)); now = ans = 0;
		cin >> n;
		rep(i, 1, n)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			plc[i] = 1; if (a[i][1] < a[i][2]) plc[i] = 2; if (a[i][plc[i]] < a[i][3]) plc[i] = 3;
			++cnt[plc[i]]; ans += a[i][plc[i]];
		}
		if (max(cnt[1], max(cnt[2], cnt[3])) <= n / 2) {cout << ans << '\n'; continue;}
		if (cnt[1] > n / 2) maxx = 1; else if (cnt[2] > n / 2) maxx = 2; else maxx = 3;
		rep(i, 1, n) if (plc[i] == maxx)
		{
			num[++now] = 1000000;
			rep(j, 1, 3) if (j != maxx) num[now] = min(num[now], a[i][maxx] - a[i][j]);
		}
		sort(num + 1, num + now + 1);
		rep(i, 1, cnt[maxx] - n / 2) ans -= num[i];
		cout << ans << '\n';
	}
	return 0;
}