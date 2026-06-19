#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int T, n, m, k;
char a[maxn][maxn];
bool vis[maxn][maxn];
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int ex(int x, int y, int d, int place, int step) {
    if (step == k) {
        return place;
    }
    int dx = x, dy = y;
    if (d == 0) {
        dy++;
    } else if (d == 1) {
        dx++;
    } else if (d == 2) {
        dy--;
    } else if (d == 3){
        dx--;
    }
    step++;
    if (check(dx,dy) && a[dx][dy] == '.'){
        if (!vis[dx][dy]) {
            place++;
            vis[dx][dy] = 1;
        }
        ex(dx, dy, d, place, step);
    } else {
        d = (d + 1) % 4;
        ex(x, y, d, place, step);
    }
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        memset(a, ' ', sizeof(a));
        memset(vis, 0, sizeof(vis));
        n = 0, m = 0, k = 0;
        int x, y, d;
        scanf("%d %d %d", &n, &m, &k);
        scanf("%d %d %d", &x, &y, &d);
        vis[x][y] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        int sum = ex(x, y, d, 1, 0);
        printf("%d", sum);
    }
    return 0;
}

