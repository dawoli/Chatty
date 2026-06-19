#include<bits/stdc++.h>
# define int long long
# define rep(i, j, k) for (int i = j; i <= k; ++i)
# define inf 10000000000000000LL
using namespace std;

int T, n, a[200005], dp[200005], det;
int lst[200005], maxx[1000005], now[1000005], mal;

signed main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
    {
        memset(lst, 0, sizeof(lst)), memset(now, 0, sizeof(now)); det = 0;
        cin >> n;
        rep(i, 1, n) {cin >> a[i]; lst[i] = now[a[i]], now[a[i]] = i;}
        rep(i, 1, n) dp[i] = -inf;
        rep(i, 1, 1000000) maxx[i] = -inf;
        dp[0] = mal = 0;
        rep(i, 2, n)
        {
            dp[i - 1] = max(mal, maxx[a[i]] + a[i]);
            det += a[i] * (a[i] == a[i - 1]), dp[i - 1] -= a[i] * (a[i] == a[i - 1]);
            maxx[a[i - 1]] = max(maxx[a[i - 1]], dp[i - 1]), mal = max(mal, dp[i - 1]);
        }
        cout << mal + det << '\n';
    }
	return 0;
}
