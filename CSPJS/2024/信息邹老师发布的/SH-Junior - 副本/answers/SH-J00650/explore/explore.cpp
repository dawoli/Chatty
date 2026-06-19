#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e3 + 5;

bool vis[N][M];
bool _m[N][M];

void solve() {
    memset(vis, 0, sizeof vis);
    int ans = 1;
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, d;
    cin >> x >> y >> d;
    vis[x][y] = 1;
    for (int i =1; i <= n; i++) {
        for (int j =1; j <= m; j++) {
            char c;
            cin >> c;
            _m[i][j] = c == 'x';
        }
    }
    while (k--) {
        int dx, dy;
        if (d == 0) {
            dx = x, dy = y + 1;
        }
        if (d == 1) {
            dx = x + 1, dy = y;
        }
        if (d == 2) {
            dx = x, dy = y - 1;
        }
        if (d == 3) {
            dx = x - 1, dy = y;
        }
        if (dx < 1 || dx > n || dy < 1 || dy > m || _m[dx][dy]) d = (d + 1) % 4;
        else {
            x = dx, y = dy;
            ans += !vis[dx][dy];
            vis[dx][dy] = 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) solve();
}