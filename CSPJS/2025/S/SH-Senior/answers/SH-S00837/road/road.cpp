#include <bits/extc++.h>

using namespace std;
namespace pbds = __gnu_pbds;

namespace {
    ifstream fin("road.in");
    ofstream fout("road.out");

    const int N = 1e4 + 5, K = 15;

    int n, m, k, fa[N + K], sz[N + K];
    long ans;
    pbds::priority_queue<tuple<int, int, int>, greater<tuple<int, int, int>>> q;
    vector<tuple<int, int, int>> h, p;

    void init() {
        iota(fa + 1, fa + n + k + 1, 1), fill(sz + 1, sz + n + 1, 1), fill(sz + n + 1, sz + n + k + 1, 0);
    }

    int find(int u) { return fa[u] ^ u ? fa[u] = find(fa[u]) : u; }

    int merge(int u, int v) {
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        return fa[v] = u, sz[u] += sz[v], u;
    }

    long work() {
        long res = 0;
        init();
        for (int u, v, w; q.size(); q.pop()) {
            tie(w, u, v) = q.top(), u = merge(find(u), find(v));
            if (u) res += w, h.push_back(q.top());
            if (sz[u] == n) break;
        }
        return res;
    }

    void update() {
        h.clear(), q.clear();
        for (auto e : p) q.push(e);
    }

    void solve() {
        fin >> n >> m >> k;
        for (int u, v, w; m--; fin >> u >> v >> w, q.push({w, u, v}));
        ans = work(), p = h, update();
        for (int i = n + 1, c; i <= n + k; update(), i++) {
            fin >> c;
            for (int j = 0, w; j < n; fin >> w, q.push({w, i, ++j}));
            long res = work() + c;
            if (res < ans) ans = res, p = h;
        }
        fout << ans << '\n';
    }
}

int main() {
    solve();
}