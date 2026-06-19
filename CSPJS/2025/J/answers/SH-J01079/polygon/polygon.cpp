#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const ll T = 10000;
ll n, a[5009], cnt[10009], cg;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll s = a[i]+1; s <= T; s++) (ans += cnt[s]) %= MOD;
        (ans += cg) %= MOD;
        (cg *= 2) %= MOD;
        for(ll s = T; s >= 1; s--) {
            if(a[i]+s > T) (cg += cnt[s]) %= MOD;
            else (cnt[a[i]+s] += cnt[s]) %= MOD;
        }
        for(ll j = 1; j < i; j++) (cnt[a[i]+a[j]] += 1) %= MOD;
    }
    cout << ans << '\n';
    return 0;
}