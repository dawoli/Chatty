#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

int T, n, m, k, x, y, d;
char mp[N][N];
bool vis[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void solve() {
    cin >> n >> m >> k >> x >> y >> d;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mp[i][j];

    memset(vis, false, sizeof(vis));
    vis[x][y] = true;
    while(k--) {
        int ux = x + dx[d], uy = y + dy[d];
        if(ux < 1 || ux > n || uy < 1 || uy > m)
            d = (d + 1) % 4;
        else if(mp[ux][uy] == '.') {
            x = ux;
            y = uy;
        } else
            d = (d + 1) % 4;
        vis[x][y] = true;
    }

    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(vis[i][j] == true)
                res++;

    cout << res << endl;
}

signed main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--)
        solve();

    return 0;
}