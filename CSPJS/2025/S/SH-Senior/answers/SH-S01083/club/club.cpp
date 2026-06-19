#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n, a[100009][3];

namespace Sub5 {
    ll f[209][109][109];
    void solve() {
        memset(f, 0, sizeof(f));
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j <= min(i, n/2); j++) for(ll k = 0; k <= min(i-j, n/2); k++) {
                if(j < n/2) f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k]+a[i+1][0]);
                if(k < n/2) f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k]+a[i+1][1]);
                if(i-j-k < n/2) f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k]+a[i+1][2]);
            }
        }
        ll ans = 0;
        for(ll j = 0; j <= n/2; j++) for(ll k = 0; k <= n/2; k++) ans = max(ans, f[n][j][k]);
        cout << ans << '\n';
    }
}

namespace TY712 {
    set<ll> c[3];
    void pour(ll x, ll y) {
        vector<pair<ll,ll>> price;
        for(ll i:c[x]) price.emplace_back(a[i][y]-a[i][x], i);
        sort(price.begin(), price.end(), greater<pair<ll,ll>>());
        for(pair<ll,ll> pr:price) {
            ll cst = pr.first, i = pr.second;
            if(cst <= 0) break;
            c[x].erase(i);
            c[y].insert(i);
        }
    }
    void work(ll x, ll y, ll z) { // decide whether to pour the first x.size()-n/2 elemets of x into y or into z
        vector<pair<ll, pair<ll,ll>>> price;
        for(ll i:c[x]) price.emplace_back(a[i][y]-a[i][x], make_pair(i, y)), price.emplace_back(a[i][z]-a[i][x], make_pair(i, z));
        sort(price.begin(), price.end(), greater<pair<ll, pair<ll,ll>>>());
        for(pair<ll, pair<ll,ll>> pr:price) {
            if(c[x].size() == n/2) break;
            ll cst = pr.first, i = pr.second.first, tgt = pr.second.second;
            if(c[x].count(i) == 0) continue;
            c[x].erase(i);
            c[tgt].insert(i);
        }
    }
    void solve() {
        for(ll i = 0; i < 3; i++) c[i].clear();
        for(ll i = 1; i <= n; i++) c[0].insert(i);
        pour(0, 1); pour(1, 2); pour(0, 2);
        // for(ll k = 0; k < 3; k++) for(ll i:c[k]) cout << i << "&" << k << endl;
        if(c[0].size() > n/2) work(0, 1, 2);
        else if(c[1].size() > n/2) work(1, 0, 2);
        else if(c[2].size() > n/2) work(2, 0, 1);
        ll ans = 0;
        for(ll k = 0; k < 3; k++) for(ll i:c[k]) ans += a[i][k];
        cout << ans << '\n';
    }
}

void solve() {
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    if(n <= 200) Sub5::solve();
    else TY712::solve();
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--) solve();
    return 0;
}