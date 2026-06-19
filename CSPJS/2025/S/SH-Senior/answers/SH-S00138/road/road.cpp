#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int M = 1000010;
using i64 = long long;
struct DSU {
    std::vector<int> fa, siz;
    DSU(int n) : fa(n + 1), siz(n + 1, 1) {
        std::iota(fa.begin(), fa.end(), 0);
    }
    inline int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    inline bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (siz[fx] < siz[fy]) swap(fx, fy);
        fa[fy] = fx, siz[fx] += siz[fy];
        return true;
    }
};
i64 res = LLONG_MAX;
vector<array<int, 3>> E, e[11];
int n, m, k, u, v, w, a[N], c[11];
inline i64 calc(int S) {
    vector<int> dig;
    i64 es = 0, ans = 0;
    for (int i = 0; i <= k; i++) {
        if (S >> i & 1) {
            es += e[i].size();
            dig.push_back(i), ans += c[i];
        }
    }
    if (ans >= res) return LLONG_MAX;
    vector<array<int, 3>> E(es);
    vector<size_t> ptr(k + 1, 0);
    int req = n + dig.size() - 1, cnt = 0;
    for (int i = 0; i < es; i++) {
        int mv = dig[0];
        for (auto &v : dig) {
            if (e[v][ptr[v]][0] < e[mv][ptr[mv]][0]) mv = v;
        }
        E[i] = e[mv][ptr[mv]++];
        if (ptr[mv] == e[mv].size()) {
            for (auto it = dig.begin(); it != dig.end(); it++) {
                if (*it == mv) {
                    dig.erase(it);
                    break;
                }
            }
        }
    }
    DSU D(n + k);
    for (auto &[w, u, v] : E) {
        if (ans >= res) return LLONG_MAX;
        if (D.merge(u, v)) ans += w, cnt++;
        if (cnt == req) break;
    }
    return ans;
}
inline void optimizeIO(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, const char *argv[]) {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    optimizeIO(), cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        E.push_back({w, u, v});
    }
    DSU D(n);
    sort(E.begin(), E.end());
    for (auto &[w, u, v] : E) {
        if (D.merge(u, v)) {
            e[0].push_back({w, u, v});
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            e[i].push_back({a[j], n + i, j});
        }
        sort(e[i].begin(), e[i].end());
    }
    for (int S = 0; S < (1 << k); S++) {
        res = min(res, calc(S << 1 | 1));
    }
    cout << res << endl;
    return 0;
}