#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
long long t, n, m, ans1 = 1e9, ans2 = 1e9;
int xy[4][2]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char a[1001][1001];
void dfs(int x, int y, long long zha, long long now)
{
    if (zha > ans1 || (zha == ans1 && now >= ans2)) return;
    if (x == n && y == m)
    {
        if (zha < ans1 || (zha == ans1 && now < ans2))
        {
            ans1 = zha;
            ans2 = now;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = x + xy[i][0], dy = y + xy[i][1];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] != '*')
        {
            if (a[dx][dy] == '.') dfs(dx, dy, zha, now + 1);
            else dfs(dx, dy, zha + 1, now + 1);
        }
    }
}
int main()
{
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        dfs(1, 1, 0, 0);
        cout << ans1 << ' ' << ans2 << '\n';
        ans1 = ans2 = 1e18;
    }
    return 0;
}
