#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k, S, c[19], a[19][10009], id[10019];
vector<pair<ll,pair<ll,ll>>> eo, e, ep;

ll root(ll x) {return id[x]==x?x:(id[x]=root(id[x]));}
void unite(ll u, ll v) {u = root(u); v = root(v); if(u != v) id[u] = v;}
bool ok(ll u, ll v) {return root(u) == root(v);}

ll work() {
    ep = eo;
    ll np = n;
    for(ll i = 1; i <= n; i++) id[i] = i;
    ll ans = 0;
    for(ll i = 0; i < k; i++) {
        if(S&(1<<i)) {
            id[++np] = np;
            ans += c[i];
            for(ll j = 1; j <= n; j++) ep.emplace_back(a[i][j], make_pair(np, j));
        }
    }
    sort(ep.begin(), ep.end());
    e.clear();
    for(pair<ll,pair<ll,ll>> edg:ep) {
        if(!ok(edg.second.first, edg.second.second)) {
            unite(edg.second.first, edg.second.second);
            e.emplace_back(edg);
            ans += edg.first;
        }
    }
    return ans;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    eo.resize(m);
    for(ll i = 0; i < m; i++) cin >> eo[i].second.first >> eo[i].second.second >> eo[i].first;
    for(ll i = 0; i < k; i++) {
        cin >> c[i];
        for(ll j = 1; j <= n; j++) cin >> a[i][j];
    }
    work();
    eo = e;
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(; S < (1<<k); S++) ans = min(ans, work());
    cout << ans;
    return 0;
}