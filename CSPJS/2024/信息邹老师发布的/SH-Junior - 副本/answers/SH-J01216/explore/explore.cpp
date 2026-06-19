#include <iostream>

using namespace std;

char c[1205][1205];
bool e[1205][1205] = {0};
int T;
int n,m,k;
int x0,y0,d0;

bool check(int nx,int ny)
{
    if(nx <= n && nx >= 1 && ny <= m && ny >= 1)
    {
        if(c[nx][ny] != 'x') return true;
        else return false;
    }
    else return false;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                e[i][j] = 0;
            }
        }
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        for(int i = 1;i <= n;i++)//i shi hang
        {
            for(int j = 1;j <= m;j++)//j shi lie
            {
                cin >> c[i][j];
            }
        }
        int x = x0,y = y0,d = d0;
        for(int i = 1;i <= k;i++)
        {
            e[x][y] = 1;
            int d1 = d;
            if(d == 0)
            {
                if(check(x,y + 1))
                {
                    y += 1;
                }
                else
                {
                    d1 = d + 1;
                    while(d1 >= 4) d1 -= 4;
                }
            }
            if(d == 1)
            {
                if(check(x + 1,y))
                {
                    x += 1;
                }
                else
                {
                    d1 = d + 1;
                    while(d1 >= 4) d1 -= 4;
                }
            }
            if(d == 2)
            {
                if(check(x,y - 1))
                {
                    y -= 1;
                }
                else
                {
                    d1 = d + 1;
                    while(d1 >= 4) d1 -= 4;
                }
            }
            if(d == 3)
            {
                if(check(x - 1,y))
                {
                    x -= 1;
                }
                else
                {
                    d1 = d + 1;
                    while(d1 >= 4) d1 -= 4;
                }
            }
            d = d1;
            e[x][y] = 1;
            //cout << "x:" << x << " y:" << y << " d:" << d <<endl;
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(e[i][j])cnt++;
            }
        }
        cout << cnt <<endl;
    }
    return 0;
}
