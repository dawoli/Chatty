#include <iostream>
#include <cstring>
using namespace std;
int t, n, m, k, x, y, d, ans;
bool vis[1001][1001];
char c[1001][1001];
void solve(int &x, int &y, int &d)
{
    int dx, dy;
    if (d == 0)
    {
        dx = x, dy = y + 1;
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && c[dx][dy] == '.')
        {
            vis[dx][dy] = 1;
            x = dx;
            y = dy;
            return;
        }
        else d = (d + 1) % 4;
    }
    else if (d == 1)
    {
        dx = x + 1, dy = y;
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && c[dx][dy] == '.')
        {
            vis[dx][dy] = 1;
            x = dx;
            y = dy;
            return;
        }
        else d = (d + 1) % 4;
    }
    else if (d == 2)
    {
        dx = x, dy = y - 1;
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && c[dx][dy] == '.')
        {
            vis[dx][dy] = 1;
            x = dx;
            y = dy;
            return;
        }
        else d = (d + 1) % 4;
    }
    else
    {
        dx = x - 1, dy = y;
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && c[dx][dy] == '.')
        {
            vis[dx][dy] = 1;
            x = dx;
            y = dy;
            return;
        }
        else d = (d + 1) % 4;
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        vis[x][y] = 1;
        for (int dep = 1; dep <= k; dep++)
            solve(x, y, d);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans += vis[i][j];
        cout << ans << '\n';
        ans = 0;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
