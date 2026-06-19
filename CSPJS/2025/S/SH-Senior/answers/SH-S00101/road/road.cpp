#include <iostream>
#include <cstring>
#include <algorithm>
int w[10010][10010];
int n, m, k;
int c[15], a[15][10010];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(w, 0x7f, sizeof(w));
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i) {
        int u, v, wi;
        std::cin >> u >> v >> wi;
        w[u][v] = w[v][u] = wi;
    }
    for (int j = 1; j <= k; ++j) {
        int c;
        std::cin >> c;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[j][i];
            const int u = i;
            if (c == 0)
                for (int v = u; v--; )
                    w[u][v] = w[v][u] = std::min(a[j][u] + a[j][v], w[u][v]);
        }
    }
    long long int ans = 0;
    for (int i = 1; i < n; ++i)
        ans += *std::min_element(&w[i][i] + 1, &w[i][n] + 1);
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j)
//            std::cout << w[i][j] << ' ';
//        std::cout << '\n';
//    }
    std::cout << ans << '\n';
    return 0;
}
