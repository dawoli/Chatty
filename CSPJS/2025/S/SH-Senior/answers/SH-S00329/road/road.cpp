#include<bits/stdc++.h>

using namespace std;

using ll = long long;
ll n, m, k;
const int N = 2e6 + 10;
struct Side {
    ll fr, to, w;
    const bool operator<(const Side& s) const {
        return w < s.w;
    }
};
vector<Side> sides{};
bool check[1010][1010]{};
pair<ll, ll> wq[1010]{};
ll v[20]{};


int main() {
#ifndef MYDEBUG
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif

    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        Side side;
        cin >> side.fr >> side.to >> side.w;
        sides.push_back(side);
    }

    for (int i = 1; i <= k; i++) {
        ll v;
        cin >> v;
        for (int j = 1; j <= n; j++) {
            ll x;
            cin >> x;
            wq[j] = {j, x};
        }
        sort(wq + 1, wq + 1 + n, [](const pair<ll, ll>& a, const pair<ll, ll> &b) {
            return a.second < b.second;
        });
        ll count = 0;
        for (int j = 1; j <= n && count < n; j++) {
            for (int w = 1; w < j && count < n; w++) {
                // cout << i << ":" << j << " " << w <<
                // " " << wq[j].second + wq[w].second + v << endl;
                sides.push_back({
                    wq[j].first,
                    wq[w].first,
                    wq[j].second + wq[w].second + v});
                count++;
            }
        }
        // cout << i << ' ' << k << endl;
    }

    // cout << sides.size() << endl;
    sort(sides.begin(), sides.end());

    ll ans = 0, count = 0;
    for (int i = 0; count < n - 1 && i < sides.size(); i++) {
        // if (i % 1000 == 0) cout << i << endl;
        Side chosen = sides[i];
        if (!check[chosen.fr][chosen.to]) {
            // cout << chosen.fr << ' ' << chosen.to << ' ' << chosen.w << endl;
            count++;
            ans += chosen.w;
            check[chosen.fr][chosen.to] = true;
            check[chosen.to][chosen.fr] = true;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     if (check[i][i]) cout << ">>>";
    // }
    
    // cout << count << endl;
    cout << ans << endl;

    return 0;
}

// ^_^
