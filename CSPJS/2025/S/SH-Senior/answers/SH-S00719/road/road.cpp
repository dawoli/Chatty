#include <bits/stdc++.h>
using namespace std;


struct edge {
    int u, v;
    long long w;
};
edge E[1000015];
vector<edge> E_deal;
int fa[1000015];
int n, m, k;
long long ans = 1e18;
long long arr[15][1000015], c[15];
typedef long long ll;

int find(int u) {
    return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void solve(int S) {
    E_deal.clear();
    long long tmp = 0;
    for (int i = 1; i <= k; i++) {
        if (S & (1 << (i - 1))) {
            // cout << S << ' ' << i << endl;
            tmp += c[i];
            for (int j = 1;j  <= n; j++) {
                E_deal.push_back({i + n, j, arr[i][j]});
            }  
        }
    }
    for (int i = 1; i <= n + k; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        E_deal.push_back(E[i]);
    }
    sort(E_deal.begin(), E_deal.end(), cmp);
    for (auto tm : E_deal) {
        int u = tm.u, v = tm.v;
        long long w = tm.w;
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            continue;
        }
        fa[fu] = fv;
        tmp += w;
    }
    ans = min(ans, tmp);
}

void solve1() {
    for (int i = 1; i <= k; i++) {
        int referto = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0) {
                referto = j;
                break;
            }
        }
        for (int j = 1; j <= n; j++) {
            E_deal.push_back({referto, j, arr[i][j]});
        }
    }
    for (int i = 1;i  <= m; i++) {
        E_deal.push_back(E[i]);
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(E_deal.begin(), E_deal.end(), cmp);
    long long tmp = 0;
    for (auto tm : E_deal) {
        int u = tm.u, v = tm.v;
        long long w = tm.w;
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            continue;
        }
        fa[fu] = fv;
        tmp += w;
    }
    ans = min(ans, tmp);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        E[i] = {u, v, w};
    }
    long long tmp = 0;
    long long tmp2 = (1ll << 30ll) - 1ll;
    for (int i = 1; i <= k; i++) {
        cin >> c[i]; tmp += c[i];
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            tmp2 &= arr[i][j];
        }
    }
    if (tmp == 0 && tmp2 == 0) {
        solve1();
        cout << ans;
        return 0;
    }
    for (int S = 0; S < (1 << k); S++) {
        if ((double)clock() / CLOCKS_PER_SEC >= 0.9) {
            break;
        }
        solve(S);
        // cout << S << ' ' << ans << endl;
    }
    cout << ans << '\n';
}