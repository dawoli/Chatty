#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct edge {int u, v, w;};
int fa[N];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(x);
}
int merge(int x, int y) {
    fa[x] = find(y);
}
edge g[N];
int c[N];
bool cmp(edge x, edge y) {
    return x.w < y.w;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[i] = {u, v, w};
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
        }
    }
    int ans = 0;
    sort(g + 1, g + 1 + m, cmp);
    for (int i = 1; i <= n; i++) {

    }

    return 0;
}
