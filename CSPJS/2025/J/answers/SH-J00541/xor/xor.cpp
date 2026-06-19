#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 500010;
ll n, k, ret, a[N], sum[N]; map<ll, bool> mp;
void solve()
{
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i-1] ^ a[i];
    mp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (mp[sum[i]^k]) mp.clear(), ret++;
        mp[sum[i]] = 1;
    }
    printf("%lld\n", ret);
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
