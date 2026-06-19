#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e3 + 8;
int T, n, m, k, x, y, d, map_[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool vis[MAX][MAX];

bool is_range(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && map_[x][y] == 1;
}

signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char inp;
                cin >> inp;
                if (inp == '.') map_[i][j] = 1;
                else map_[i][j] = 0;
            }
        }

        int ans = 1;
        memset(vis, 0, sizeof(vis));
        vis[x][y] = 1;
        while (k--)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (is_range(nx, ny))
            {
                if (!vis[nx][ny]) ans++;
                vis[nx][ny] = 1;
                x = nx;
                y = ny;
            }
            else d = (d + 1) % 4;
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
