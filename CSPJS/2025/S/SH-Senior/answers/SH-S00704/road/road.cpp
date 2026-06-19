#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;

namespace AugustLight {
    const int MAXK = 10 + 1;
    const int MAXN = 1e4 + MAXK + 5; // n + k
    int n, m, k;
    struct Edge {
        int u, v;
        ll w;
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
    };
    vector<Edge> E1;
    ll c[MAXK];
    ll a[MAXK][MAXN];

    struct DSU {
        int fa[MAXN], siz[MAXN];
        void init(int n) {
            rep(u, 1, n)
                fa[u] = u, siz[u] = 1;
        }
        int find(int u) {
            return u == fa[u] ? u : (fa[u] = find(fa[u]));
        }
        void merge(int u, int v) {
            u = find(u), v = find(v);
            if (u == v)
                return;
            if (siz[u] > siz[v])
                swap(u, v);
            fa[u] = v;
            siz[v] += siz[u];
        }
        bool same(int u, int v) {
            return find(u) == find(v);
        }
    };

    int village(int u) {
        return u + n;
    }

    namespace SubA {
        bool valid() {
            rep(j, 1, k) {
                if (c[j] != 0)
                    return false;
                bool flg = true; // No 0
                rep(u, 1, n)
                    if (a[j][u] == 0)
                        flg = false;
                if (flg)
                    return false;
            }
            return true;
        }
        ll solve(int mask) {
            ll ans = 0;
            vector<Edge> E2;
            rep(j, 1, k) if (mask >> (j-1) & 1) {
                ans += c[j];
                rep(u, 1, n)
                    E2.emplace_back(village(j), u, a[j][u]);
            }
            DSU dsu; dsu.init(n + k);
            //cerr << E2.size() << '\n';
            sort(E2.begin(), E2.end(), [](Edge &A, Edge &B) {
                return A.w < B.w;
            });
            vector<Edge> E;
            int ptr = 0;
            for (auto e1 : E1) {
                while (ptr != (int)E2.size()) {
                    auto e2 = E2[ptr];
                    if (e2.w <= e1.w)
                        E.push_back(e2);
                    else
                        break;
                    ptr++;
                }
                E.push_back(e1);
            }
            while (ptr != (int)E2.size()) {
                auto e2 = E2[ptr];
                E.push_back(e2);
                ptr++;
            }
            //cerr << E.size() << endl;
            
            for (auto e : E) {
                int u = e.u, v = e.v; ll w = e.w;
                if (!dsu.same(u, v)) {
                    ans += w;
                    dsu.merge(u, v);
                    //cerr << u << "<->" << v << " " << w << endl;
                }
            }
            return ans;
        }
        ll Main() {
            //cerr << "Sub A" << endl;
            return SubA::solve((1 << k) - 1);
        }
    }

    namespace BF {
        ll Main() {
            int tot = (1 << k) - 1;
            ll mn = 1e18;
            rep(mask, 0, tot)
                mn = min(mn, SubA::solve(mask));
            return mn;
        }
    }

    void Main() {
        cin >> n >> m >> k;
        rep(i, 1, m) {
            int u, v; ll w; cin >> u >> v >> w;
            E1.emplace_back(u, v, w);
        }
        rep(j, 1, k) {
            cin >> c[j];
            rep(u, 1, n)
                cin >> a[j][u];
        }

        sort(E1.begin(), E1.end(), [](Edge &A, Edge &B) {
            return A.w < B.w;
        });

        if (SubA::valid())
            cout << SubA::Main() << '\n';
        else
            cout << BF::Main() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    AugustLight::Main();
    return 0;
}