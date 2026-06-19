#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,k,sx,sy,sd,nx,ny,nd,cnt;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char maps[1010][1010];
int vis[1010][1010];
signed main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&m,&k);
        scanf("%lld %lld %lld",&sx,&sy,&sd);
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                cin >> maps[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        cnt = 1, vis[sx][sy] = 1;
        nx = sx, ny = sy, nd = sd;
        while (k--) {
            nx += dx[nd], ny += dy[nd];
            if (nx < 1 or nx > n or ny < 1 or ny > m or maps[nx][ny] == 'x') {
                nx -= dx[nd], ny -= dy[nd];
                nd = (nd + 1) % 4;
            } else {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1, ++cnt;
                }
            }
            if (cnt == m * n) {
                break;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}