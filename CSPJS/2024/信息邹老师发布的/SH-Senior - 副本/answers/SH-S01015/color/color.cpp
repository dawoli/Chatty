// guess: same value=same color

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n, a[200009];

namespace Sub1_4 {
    ll clr[200009];
    void solve() {
        ll ans = 0;
        for(ll i = 0; i < (1<<n)-1; i++) {
            for(ll j = 1; j <= n; j++) clr[j] = (i>>(j-1))&1;
            ll lr = 0, lb = 0, sc = 0;
            for(ll j = 1; j <= n; j++) {
                if(clr[j] == 0) {
                    sc += (a[lr]==a[j]?a[j]:0);
                    lr = j;
                }
                else {
                    sc += (a[lb]==a[j]?a[j]:0);
                    lb = j;
                }
            }
            ans = max(ans, sc);
        }
        cout << ans << endl;
    }
}

namespace Sub13_15 {
    ll clr[200009];
    void solve(map<ll,ll> s) {
        ll ans = 0;
        ll nClr = s.size();
        for(ll i = 0; i < (1<<nClr)-1; i++) {
            for(ll j = 1; j <= nClr; j++) clr[j] = (i>>(j-1))&1;
            ll lr = 0, lb = 0, sc = 0;
            for(ll j = 1; j <= n; j++) {
                if(clr[s[a[j]]] == 0) {
                    sc += (a[lr]==a[j]?a[j]:0);
                    lr = j;
                }
                else {
                    sc += (a[lb]==a[j]?a[j]:0);
                    lb = j;
                }
            }
            ans = max(ans, sc);
        }
        cout << ans << endl;
    }
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(ll i = 1; i <= n; i++) cin >> a[i];
        if(n <= 15) Sub1_4::solve();
        else {
            map<ll,ll> mp;
            ll xd = 0;
            for(ll i = 1; i <= n; i++) if(mp[a[i]] == 0) mp[a[i]] = ++xd;
            if(mp.size() <= 10) Sub13_15::solve(mp);
            else Sub13_15::solve(mp);
        }
    }
    return 0;
}