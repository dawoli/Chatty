#include <bits/stdc++.h>
using namespace std;
int n, m, a[110];
const int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}};
struct pac
{
    int x, y, di;
    void move()
    {
        // printf("Before moving: direction=%d x=%d y=%d\n", di, x, y);
        if (x == n)
        {
            if (di == 0)
            {
                di = 1;
            }
            else if (di == 1)
            {
                di = 2;
            }
        }
        else if (x == 1)
        {
            if (di == 2)
            {
                // if (x == 1 && y == 2 && di == 2)
                // {
                //     puts("yee");
                // }
                di = 1;
                // cout << di << endl;
            }
            else if (di == 1)
            {
                di = 0;
            }
        }
        x += d[di][0];
        y += d[di][1];
        // printf("After moving: direction=%d x=%d y=%d\n", di, x, y);
    }
};
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++)
    {
        cin >> a[i];
    }
    int R = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    pac p = {1, 1, 0};
    int cnt = 1;
    while (a[cnt] != R)
    {
        p.move();
        cnt ++;
    }
    cout << p.y << ' ' << p.x << endl;
    return 0;
}