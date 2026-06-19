#include <bits/stdc++.h>
using namespace std;

char c[1010][1010];
bool flag[1010][1010];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> c[i][j];
            }
        }
        long long cnt = 1;
        memset(flag,0,sizeof(flag));
        flag[x][y] = 1;
        for (int i = 1; i <= k; i++)
        {
            int nx,ny;
            if (d == 0)
            {
                nx = x;
                ny = y + 1;
            }
            if (d == 1)
            {
                nx = x + 1;
                ny = y;
            }
            if (d == 2)
            {
                nx = x;
                ny = y - 1;
            }
            if (d == 3)
            {
                nx = x - 1;
                ny = y;
            }
            if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            if (!flag[nx][ny]) cnt++;
            x = nx;
            y = ny;
            flag[x][y] = 1;
        }
        cout << cnt << endl;
    }
    return 0;
}
