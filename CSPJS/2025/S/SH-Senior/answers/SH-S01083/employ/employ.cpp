#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
ll n, m, s[509], c[509], p[19];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    bool f = true;
    for(ll i = 1; i <= n; i++) {
        char c;
        cin >> c;
        s[i] = c-'0';
        f &= s[i];
    }
    for(ll i = 1; i <= n; i++) cin >> c[i];
    if(n <= 10) {
        for(ll i = 1; i <= n; i++) p[i] = i;
        ll ans = 0;
        do {
            ll ct = 0, r = 0;
            for(ll i = 1; i <= n; i++) {
                if(ct >= c[p[i]]) continue;
                if(s[i]) r++;
                else ct++;
            }
            if(r >= m) ans++;
        } while(next_permutation(p+1, p+n+1));
        cout << ans;
        return 0;
    }
    if(m == n) {
        ll ans = 1;
        for(ll i = 1; i <= n; i++) (ans *= i) %= MOD;
        cout << ans;
        return 0;
    }
    if(f) {
        ll np = n;
        for(ll i = 1; i <= n; i++) np -= (c[i] == 0);
        ll ans = 1;
        for(ll i = 1; i <= np; i++) (ans *= i) %= MOD;
        cout << ans;
        return 0;
    }
    return 0;
}