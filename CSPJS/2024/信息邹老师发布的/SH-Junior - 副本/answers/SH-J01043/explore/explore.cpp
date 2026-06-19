#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int n, m, k;
bool f[N][N];
bool vis[N][N];
void fun(int x, int y, int d)
{
    for (int i = 1; i <= k; i++)
    {
        int xx = x + dx[d], yy = y + dy[d];
        if (xx < 1 || xx > n || yy < 1 || yy > m || f[xx][yy])
            d = (d + 1) % 4;
        else
            x = xx, y = yy, vis[xx][yy] = 1;
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof vis);
        memset(f, 0, sizeof f);
        int x0, y0, d;
        cin >> n >> m >> k >> x0 >> y0 >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                f[i][j] = (c == 'x' ? 1 : 0);
            }
        vis[x0][y0] = 1;
        fun(x0, y0, d);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans += vis[i][j];
        cout << ans << endl;
    }
    return 0;
}