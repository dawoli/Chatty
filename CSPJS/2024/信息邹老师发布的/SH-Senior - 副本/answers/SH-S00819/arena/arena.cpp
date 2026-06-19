#include<bits/stdc++.h>
# define ll long long
# define rep(i, j, k) for (int i = j; i <= k; ++i)
using namespace std;

int T, n, m, a[150005], c[150005], k, xr[4], hhh;
string s[25];
bool d[270005];
int dp[270005][20], ssd[270005];
ll ans[270005];
int ly[270005], lv[270005], stk[270005], lvm[270005], minn[270005], l, r;
void solve(int x)
{
    stk[l = r = 1] = (1 << (k - x)), lvm[1] = (1 << x), minn[1] = 0;
    while (l <= r)
    {
        int u = stk[l];
    //   cout << u << ' ' << lvm[l] << ' ' << minn[l] << endl;
        if (u >= (1 << k)) {int lll = (1 << (x - 1)) + 1, r = lvm[l] + 1; if (minn[l] > a[u - (1 << k) + 1]) r = min(r, u - (1 << k));
                if (lvm[l] >= (1 << (x - 1)) + 1 && lll <= r) ans[(1 << (x - 1)) + 1] += u - (1 << k) + 1, ans[r + 1] -= u - (1 << k) + 1;}
        else
        {
            stk[++r] = 2 * u + d[u], lvm[r] = lvm[l], minn[r] = max(minn[r], ly[u]);
            stk[++r] = 2 * u + !d[u], lvm[r] = min(lvm[l], lv[u]), minn[r] = minn[u];
        }
        ++l;
    }
}
signed main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) cin >> c[i];
	while ((1 << k) < n) ++k;
	rep(i, 1, k) cin >> s[i];
	rep(i, 0, k - 1) rep(j, 0, (1 << i) - 1) d[j + (1 << i)] = s[k - i][j] - '0', ly[j + (1 << i)] = k - i;
	cin >> T;
	while (T--)
    {
        memset(ans, 0, sizeof(ans));
        rep(i, 0, 3) cin >> xr[i];
        rep(i, 1, n) a[i] ^= xr[i & 3];
        rep(i, 0, (1 << k) - 1) {rep(j, 0, k) dp[i + (1 << k)][j] = i; dp[i + (1 << k)][min(a[i + 1], k)] = (1 << k);}
        for (int i = (1 << k) - 1; i; --i)
        {
            int u = 2 * i + d[i], v = 2 * i + !d[i];
            rep(t, ly[i], k) dp[i][t] = dp[u][t];
            lv[i] = 0;
            rep(t, 0, ly[i] - 1) dp[i][t] = 0, lv[i] = max(lv[i], dp[u][t]);
            rep(t, 0, k) dp[i][t] = max(dp[i][t], min(lv[i], dp[v][t]));
        }
     //   rep(i, 1, (1 << (k + 1)) - 1) {rep(j, 0, 3) cout << dp[i][j] << ' '; cout << lv[i] << endl;}
        rep(i, 1, k) solve(i);
        rep(i, 1, (1 << k)) ans[i] += ans[i - 1];
        ans[1]++;
        ll al = 0;
        rep(i, 1, m) al ^= (i * ans[c[i]]);
        cout << al << '\n';
     //  rep(i, 1, n) cout << ans[i] << ' '; cout << endl;
        rep(i, 1, n) a[i] ^= xr[i & 3];
    }
	return 0;
}
