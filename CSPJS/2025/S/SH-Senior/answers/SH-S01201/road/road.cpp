#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> EDGE;
const ll N = 1e4 + 5;
const ll M = 1e6 + 5;
const ll K = 15;
const ll INF = 0x3F3F'3F3F'3F3F'3F3F;
ll n, m, k, c[K], a[K][N];

vector<EDGE> es;
vector<EDGE> ges;
void abe(ll u, ll v, ll w) { es.push_back({w, {u, v}}); }

ll fa[N + K];
void init()
{
    for (ll i = 0; i < n + k; i++)
        fa[i] = i;
}
ll find(ll x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(ll x, ll y)
{
    x = find(x), y = find(y);
    if (x != y)
        fa[x] = y;
}

ll mst(ll state)
{
    ll ans = 0;
    init();
    priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;
    if (state == 0)
        for (const auto &e : es)
            pq.push(e);
    else
        for (const auto &e : ges)
            pq.push(e);
    for (ll i = 0; i < k; i++)
        if ((1 << i) & state)
        {
            // cerr << "Village: " << i << " " << c[i] << endl;
            ans += c[i];
            for (ll j = 0; j < n; j++)
                pq.push({a[i][j], {n + i, j}});
        }
    ll cnt = n + __builtin_popcount(state) - 1;
    while (!pq.empty())
    {
        ll w = pq.top().first;
        ll u, v;
        tie(u, v) = pq.top().second;
        pq.pop();
        if (find(u) != find(v))
        {
            ans += w, merge(u, v);
            if (state == 0)
                ges.push_back({w, {u, v}});
            // cerr << "Fix Road: " << u << " <-> " << v << "  " << w << endl;
            cnt--;
        }
        if (!cnt)
            return ans;
    }
    // assert(0);
    return INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef LOCAL
    ignore = freopen("road.in", "r", stdin);
    ignore = freopen("road.out", "w", stdout);
    // #else
    // ignore = freopen("road.err", "w", stderr);
    // #endif
    cin >> n >> m >> k;
    for (ll i = 0, u, v, w; i < m; i++)
        cin >> u >> v >> w, abe(u - 1, v - 1, w);
    for (ll i = 0; i < k; i++)
    {
        cin >> c[i];
        for (ll j = 0; j < n; j++)
            cin >> a[i][j];
    }
    ll ans = INF;
    for (ll state = 0; state < (1 << k); state++)
    {
        ll cur = mst(state);
        ans = min(ans, cur);
        // cerr << "State " << bitset<K>(state) << ": " << cur << endl
        //      << endl;
    }
    cout << ans << endl;
    // cerr << "Time Usage: " << clock() << endl;
    return 0;
}