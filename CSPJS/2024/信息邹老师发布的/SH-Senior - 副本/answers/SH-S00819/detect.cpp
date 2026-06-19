#include<bits/stdc++.h>
# define int long long
# define rep(i, j, k) for (int i = j; i <= k; ++i)
using namespace std;

int T, n, m, l, lim, d[100005], v[100005], a[100005], p[100005], dp[100005], cnt;
vector < int > mst[100005];

signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
    {
        cin >> n >> m >> l >> lim; cnt = 0;
        rep(i, 1, n) cin >> d[i] >> v[i] >> a[i];
        rep(i, 1, m) cin >> p[i], mst[i].clear();
        rep(i, 1, n)
        {
            if (v[i] <= lim && a[i] <= 0) continue;
            if (v[i] > lim && a[i] >= 0)
            {
                int pos = lower_bound(p + 1, p + m + 1, d[i]) - p;
                if (pos <= m) mst[m].push_back(pos - 1), ++cnt;//, cerr << i << ' ' << pos << ' ' << m << endl;
                continue;
            }
            if (v[i] <= lim)
            {
                int kkr = d[i] + (lim * lim - v[i] * v[i]) / (2 * a[i]) + 1;
                int pos = lower_bound(p + 1, p + m + 1, kkr) - p;
                if (pos <= m) mst[m].push_back(pos - 1), ++cnt;//, cerr << i << ' ' << pos << ' ' << m << endl;
            }
            else
            {
                int kkr = d[i] + (v[i] * v[i] - lim * lim) / (2 * -a[i]);
                if ((v[i] * v[i] - lim * lim) % (2 * -a[i]) == 0) --kkr;
                int yuan = lower_bound(p + 1, p + m + 1, d[i]) - p, pos = upper_bound(p + 1, p + m + 1, kkr) - p - 1;
                if (yuan <= pos) mst[pos].push_back(yuan - 1), ++cnt;// cerr << i << ' ' << yuan << ' ' << pos << endl;
            }
        }
        rep(i, 1, m) {dp[i] = dp[i - 1]; for (int j = 0; j < mst[i].size(); ++j) dp[i] = max(dp[i], dp[mst[i][j]] + 1);}
        cout << cnt << ' ' << m - dp[m] << '\n';
    }
	return 0;
}
