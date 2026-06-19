#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
vector<int> tree[MAXN];
int army[MAXN], parent[MAXN];
int in[MAXN], out[MAXN], timer = 0;
long long bit[MAXN];
int n, m, q;

void dfs(int u, int p) {
    parent[u] = p;
    in[u] = ++timer;
    for (int v : tree[u]) {
        dfs(v, u);
    }
    out[u] = timer;
}

void add(int x, long long v) {
    for (; x <= n; x += x & -x) bit[x] += v;
}
long long query(int x) {
    long long res = 0;
    for (; x; x -= x & -x) res += bit[x];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> army[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
    }
    dfs(1, 0);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        if (p == 1) {
            add(in[x], y);
            add(out[x] + 1, -y);
        }
        else {
            add(in[x], y);
            if (parent[x] != 0) {
                add(in[parent[x]], y);
            }
            for (int v : tree[x]) {
                add(in[v], y);
            }
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a;
        cin >> a;
        cout << army[a] + query(in[a]) << "\n";
    }
    return 0;
}