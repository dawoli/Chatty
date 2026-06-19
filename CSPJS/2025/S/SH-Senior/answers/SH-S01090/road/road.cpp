#include <bits/stdc++.h>
using namespace std;
#define oo 1000005
int n, m, k, u[oo], v[oo], w[oo], c[oo][oo], ans;
inline void calc() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = j; k <= n; ++k) {
                if (c[i][j] >= 1 && c[i][k] >= 1) {
                    ++c[j][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (c[i][j] > 1) {
                for (int k = 1; k <= m; ++k) {
                    if ((u[k] == i && v[k] == j) || (u[k] == j || v[k] == i)) {
                        ans -= w[i];
                    }
                }
            }
        }
    }
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        cin >> u[i] >> v[i] >> w[i];
        c[u[i]][v[i]] += 1, c[v[i]][u[i]] += 1;
        ans += w[i];
    }
    calc();
    cout << ans;
    return 0;
}