#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 110;
ll n, m, tmp, a[N];
void solve()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n*m; i++) scanf("%lld", &a[i]);
    tmp = a[1];
    sort(a + 1, a + n*m + 1, greater<ll>());
    ll x = 1, y = 1;
    for (ll i = 1; i <= n*m; i++)
    {
        if (a[i] == tmp) return printf("%lld %lld\n", y, x), void();
        if (((y&1) && x == n) || (y % 2 == 0 && x == 1)) y++;
        else if (y & 1) x++;
        else x--;
    }
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
