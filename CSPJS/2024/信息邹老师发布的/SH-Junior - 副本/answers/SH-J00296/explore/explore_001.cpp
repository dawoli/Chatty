#include <iostream>
#include <cstring>
using namespace std;
char map[1010][1010];
bool vis[1010][1010];
int n, m, k;
int x0, y0, d0;
int dw[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int cnt = 1;
void sol1()
{
	cnt = 1;
    int x = x0, y = y0, d = d0;
    vis[x0][y0] = true;
    for (int i = 0; i < k; i ++)
    {
        int tx = x + dw[d][0], ty = y + dw[d][1];
        if (tx < 1 || tx > n || ty < 1 || ty > m || map[tx][ty] == 'x')
        {
        	// printf("tx: %d ty: %d d: %d\n", tx, ty, d);
            d = (d + 1) % 4;
            // puts("turn");
        }
        else
        {
        	// puts("move");
            if (!vis[tx][ty])
            {
            	// puts("new visit");
                cnt ++;
                vis[tx][ty] = true;
            }
            x = tx;
            y = ty;
        }
    }
    cout << cnt << endl;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t --)
    {
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                cin >> map[i][j];
            }
        }
        sol1();
        // for (int i = 1; i <= n; i ++)
        // {
        // 	for (int j = 1; j <= m; j ++)
        // 	{
        // 		cout << vis[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
