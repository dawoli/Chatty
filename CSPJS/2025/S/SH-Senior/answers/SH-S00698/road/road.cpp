#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using LL = long long;

struct Edge {
    LL u, v, w;
};

bool operator < (Edge x, Edge y) {
    if (x.w != y.w) {
        return x.w > y.w;
    }
    if (x.u != y.u) {
        return x.u > y.u;
    }
    return x.v > y.v;
}

struct UnionFindSet {
    vector<LL> p;

    UnionFindSet(LL n) {
        p.assign(n + 10, 0);
        for (LL i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    LL find(LL u) {
        if (u == p[u]) {
            return u;
        }
        LL ret = find(p[u]);
        p[u] = ret;
        return ret;
    }

    void join(LL u, LL v) {
        LL root_u = find(u);
        LL root_v = find(v);
        if (root_u > root_v) {
            swap(root_u, root_v);
        }
        p[root_v] = root_u;
    }
};

const LL INF = 1e18 + 10;
const LL N = 1e4 + 10;
const LL K = 20;
LL city_cost[K], road_cost[K][N];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, m, k;
    cin >> n >> m >> k;
    priority_queue<Edge> _q;
    for (LL i = 1; i <= m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        _q.push({u, v, w});
    }
    LL cnt = 0;
    vector<Edge> edges;
    UnionFindSet _ufs(n);
    while (cnt < n - 1) {
        Edge x = _q.top(); _q.pop();
        LL u = x.u;
        LL v = x.v;
        if (_ufs.find(u) == _ufs.find(v)) {
            continue;
        }
        edges.push_back(x);
        _ufs.join(u, v);
        cnt++;
    }
    while (LL(edges.size()) > n + k) {
        edges.pop_back();
    }
    for (LL i = 1; i <= k; i++) {
        cin >> city_cost[i];
        for (LL j = 1; j <= n; j++) {
            cin >> road_cost[i][j];
        }
    }
    LL min_cost = INF;
    for (LL state = 0; state < (1 << k); state++) {
        priority_queue<Edge> q;
        for (Edge x : edges) {
            q.push(x);
        }
        UnionFindSet ufs(n + k);
        LL town_cnt = 0;
        LL cost_sum = 0;
        for (LL i = 1; i <= k; i++) {
            if (state & (1 << (i - 1))) {
                cost_sum += city_cost[i];
                for (LL j = 1; j <= n; j++) {
                    q.push({n + i, j, road_cost[i][j]});
                }
                town_cnt++;
            }
        }
        LL edge_cnt = 0;
        while (edge_cnt < n + town_cnt - 1) {
            Edge x = q.top(); q.pop();
            LL u = x.u;
            LL v = x.v;
            LL w = x.w;
            if (ufs.find(u) == ufs.find(v)) {
                continue;
            }
            ufs.join(u, v);
            cost_sum += w;
            edge_cnt++;
        }
        min_cost = min(min_cost, cost_sum);
    }
    cout << min_cost << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
