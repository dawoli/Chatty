#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
const ll MOD = 998244353;
ll n, m, c[N], p[N], fact[N], ifact[N];
string s;

ll quickPow(ll a, ll b)
{
    ll ans = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * tmp) % MOD;
        tmp = (tmp * tmp) % MOD;
        b >>= 1;
    }
    return ans;
}
ll inv(ll x) { return quickPow(x, MOD - 2); }
void init()
{
    fact[1] = 1;
    for (ll i = 2; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[0] = ifact[1] = 1;
    for (ll i = 2; i < N; i++)
        ifact[i] = ifact[i - 1] * inv(i) % MOD;
}
ll A(ll n, ll m) { return fact[n] * ifact[n - m] % MOD; }
ll C(ll n, ll m) { return A(n, m) * ifact[m] % MOD; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef LOCAL
    ignore = freopen("employ.in", "r", stdin);
    ignore = freopen("employ.out", "w", stdout);
    // #else
    // ignore = freopen("employ.err", "w", stderr);
    // #endif
    init();
    cin >> n >> m >> s;
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    for (ll i = 0; i < n; i++)
        p[i] = i;
    ll ans = 0;
    do
    {
        // for (ll i = 0; i < n; i++)
        //     cerr << c[p[i]] << " ";
        // cerr << endl;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
            if (s[i] == '0' || cnt >= c[p[i]])
                cnt++;
        if (n - cnt >= m)
            ans++;
    } while (next_permutation(p, p + n));
    cout << ans << endl;
    // cout << A(n, n) << endl;
    return 0;
}

// 这是容斥计数吗……？

// Welcome to my, world
// Renew your definition
// World, so high
// Let me show
// And here my declaration
// No more ties

// May the journey lead us starward
