#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int x, y, d;
const int turn[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char c[10005][10005];
set<pair<int, int>> se;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(c, 0, sizeof(c));
        se.clear();
        scanf("%d%d%d\n", &n, &m, &k);
        scanf("%d%d%d\n", &x, &y, &d);
        se.insert({x, y});
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                c[i][j] = getchar();
            }
            getchar();
        }
        for (int i = 1; i <= k; ++i)
        {
            if (d % 2)
            {
                if (x + turn[d][0] <= n && x + turn[d][0] >= 1 && c[x + turn[d][0]][y] == '.')
                {
                    x += turn[d][0], se.insert({x, y});
                }
                else
                {
                    d = (d + 1) % 4;
                }
            }
            else
            {
                if (y + turn[d][1] <= m && y + turn[d][1] >= 1 && c[x][y + turn[d][1]] == '.')
                {
                    y += turn[d][1], se.insert({x, y});
                }
                else
                {
                    d = (d + 1) % 4;
                }
            }
        }
        printf("%d\n", se.size());
    }
    return 0;
}