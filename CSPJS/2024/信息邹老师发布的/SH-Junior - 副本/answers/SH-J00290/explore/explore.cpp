#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool xx[1010][1010];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        for (int i = 0;i <= n + 1;i++)
        {
            for (int j = 0;j <= m + 1;j++)
            {
                a[i][j] = 'x';
            }
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
                xx[i][j] = false;
            }
        }
        for (int i = 1;i <= k;i++)
        {
            xx[x][y] = true;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (a[nx][ny] != '.')
            {
                d = (d + 1) % 4;
            }
            else
            {
                x = nx;
                y = ny;
            }
        }
        xx[x][y] = true;
        int cnt = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                if (xx[i][j])
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
