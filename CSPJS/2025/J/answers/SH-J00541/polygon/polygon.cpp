#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5010, mod = 998244353;
ll n, ret, a[N], dp[N], f[N], finv[N];
ll qpow(ll a, ll b, ll ret = 1) { while (b) { if (b&1) ret *= a, ret %= mod; a *= a, a %= mod, b >>= 1; } return ret; }
ll C(ll n, ll m) { return f[n] * finv[n-m] % mod * finv[m] % mod; }
void dfs(ll dep, ll mx, ll cnt)
{
    if (dep == n + 1)
    {
        if (cnt > mx * 2) ret++;
        return ;
    }
    dfs(dep + 1, a[dep], cnt + a[dep]);
    dfs(dep + 1, mx, cnt);
}
bool check1()
{
    for (ll i = 2; i <= n; i++)
        if (a[i] != a[i-1]) return false;
    return true;
}
void solve()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    if (n <= 20) dfs(1, 0, 0), printf("%lld\n", ret % mod);
    else if (check1())
    {
        f[0] = finv[0] = 1;
        for (ll i = 1; i <= n; i++) f[i] = f[i-1] * i % mod, finv[i] = qpow(f[i], mod-2);
        for (ll i = 3; i <= n; i++) ret += C(n, i), ret %= mod;
        printf("%lld\n", ret);
    }
    else
    {
        dp[0] = 1;
        for (ll i = 1; i <= n; i++)
        {
            ll cnt = 0;
            for (ll j = 0; j <= a[i]; j++) cnt += dp[j], cnt %= mod;
            ret += qpow(2, i-1) - cnt + mod, ret %= mod;
            for (ll j = a[n]; j >= a[i]; j--) dp[j] += dp[j-a[i]], dp[j] %= mod;
        } printf("%lld\n", ret);
    }
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
