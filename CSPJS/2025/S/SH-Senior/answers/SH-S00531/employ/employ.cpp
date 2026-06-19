#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 20, mod = 998244353;
ll n, m, c[N], dp[(1LL<<18)+5][N]; char s[N];
void solve()
{
    scanf("%lld%lld%s", &n, &m, s+1);
    for (ll i = 0; i < n; i++) scanf("%lld", &c[i]);
    dp[0][0] = 1;
    for (ll i = 1; i < (1LL<<n); i++)
    {
        ll cnt = 0;
        for (ll j = 0; j < n; j++)
            if ((i>>j)&1) cnt++;
        for (ll j = 0; j <= cnt; j++)
            for (ll k = 0; k < n; k++) if ((i>>k)&1)
            {
                if (s[cnt] == '1' && c[k] > j) dp[i][j] += dp[i^(1LL<<k)][j];
                else if (j && (s[cnt] == '0' || c[k] <= j-1)) dp[i][j] += dp[i^(1LL<<k)][j-1];
                dp[i][j] %= mod;
            }
//        for (ll j = 0; j <= cnt; j++) printf("%lld %lld\n", j, dp[i][j]);
    }
    ll ret = 0;
    for (ll i = 0; i <= n-m; i++) ret += dp[(1LL<<n)-1][i], ret %= mod;
    printf("%lld\n", ret);
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
