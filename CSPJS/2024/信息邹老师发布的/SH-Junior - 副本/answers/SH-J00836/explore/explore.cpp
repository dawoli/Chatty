#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

char c[1010][1010];
bool vis[1010][1010];

int n , m;

int dx[] = {0 , 1 , 0 , -1};
int dy[] = {1 , 0 , -1 , 0};

bool chk(int x , int y)
{
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (c[x][y] == 'x') return false;
    return true;
}

int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    int T;
    scanf("%d" , &T);
    while (T--)
    {
        memset(vis , false , sizeof(vis));
        int k , x , y , d;
        cin >> n >> m >> k >> x >> y >> d;
        vis[x][y] = true;
        //printf("%d %d %d %d %d %d\n" , n , m , k , x , y , d);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //printf("(%d,%d):" , i , j);
                cin >> c[i][j];
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (chk(x + dx[d] , y + dy[d]))
            {
                x += dx[d];
                y += dy[d];
                vis[x][y] = true;
                //printf("#1:x=%d,y=%d,d=%d\n" , x , y , d);
            }
            else
            {
                d = (d + 1) % 4;
                //printf("#2:x=%d,y=%d,d=%d\n" , x , y , d);
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j]) cnt++;
            }
        }
        printf("%d\n" , cnt);
    }
    return 0;
}
